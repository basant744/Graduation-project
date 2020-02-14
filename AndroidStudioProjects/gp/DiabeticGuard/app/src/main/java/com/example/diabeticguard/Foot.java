package com.example.diabeticguard;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class Foot extends AppCompatActivity {

    private FirebaseDatabase firebaseDatabase = FirebaseDatabase.getInstance();
    private DatabaseReference reff = firebaseDatabase.getReference();
    private DatabaseReference pressure= reff.child("pressure");
    private DatabaseReference temperature = reff.child("temperature");

    public int pre,temp;
    TextView temptxt,pressurtxt;
    ImageView p1color;
    Button green,yellow,care;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_foot2);

        care=findViewById(R.id.care);
//        green=findViewById(R.id.green);
//        yellow=findViewById(R.id. yellow);

        pressurtxt=findViewById(R.id.pressuretxt);
        temptxt=findViewById(R.id.temptxt);


         p1color=findViewById(R.id.p1color);



        care.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent=new Intent(Foot.this,daily_care.class);
                startActivity(intent);
            }
        });

//        green.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//
//
//                int gree= Color.parseColor("#1BEE30");
//                p1color.setColorFilter(gree);
//            }
//        });
//
//        yellow.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//
//                int gree= Color.parseColor("#F0AE09");
//                p1color.setColorFilter(gree);
//            }
//        });
    }

    protected void onStart() {
        super.onStart();
        temperature.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {

                String message = dataSnapshot.getValue(String.class);
                temp= Integer.parseInt(message);

                temptxt.setText(message);
                if (temp == 38) {

                    Toast.makeText(getApplicationContext(),"High Temperature ",
                            Toast.LENGTH_LONG).show();

                }

            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });


        pressure.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {

                String message = dataSnapshot.getValue(String.class);
                pre= Integer.parseInt(message);

                pressurtxt.setText(message);

                if ( pre <= 5) {
                    int value= Color.parseColor("#AAA8A9");
                    p1color.setColorFilter(value);




                }
                else if(pre <= 34 && pre> 6 ){
                    int value= Color.parseColor("#335bff");
                    p1color.setColorFilter(value);
                }

                else if(pre <= 85 && pre >35 ){
                    int value= Color.parseColor("#fe7b07");
                    p1color.setColorFilter(value);

                }
                else{
                    Toast.makeText(getApplicationContext(),"High Pressure ",
                            Toast.LENGTH_SHORT).show();
                    int value= Color.parseColor("#f51506");
                    p1color.setColorFilter(value);

                }

            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });


    }
}
