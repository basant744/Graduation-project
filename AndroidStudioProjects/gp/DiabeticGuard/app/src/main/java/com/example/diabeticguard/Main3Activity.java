package com.example.diabeticguard;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

public class Main3Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);
        //   Button video=findViewById(R.id.video);

        ImageButton foods=findViewById(R.id.foods);
        ImageButton medication=findViewById(R.id.medication);
        ImageButton foot=findViewById(R.id.foot);
        ImageButton pressure=findViewById(R.id.bloodpressure);
        ImageButton laboratory=findViewById(R.id.laboratory);


        foods.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent log=new Intent(getBaseContext(),food.class);
                startActivity(log);
            }
        });


        medication.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent log=new Intent(getBaseContext(),medication.class);
                startActivity(log);
            }
        });

       pressure.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent log=new Intent(getBaseContext(),blood_pressure.class);
                startActivity(log);
            }
        });

       laboratory.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent log=new Intent(getBaseContext(),laboratory.class);
                startActivity(log);
            }
        });


        foot.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent log=new Intent(getBaseContext(),Foot.class);
                startActivity(log);
            }
        });



//        video.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                Intent log=new Intent(getBaseContext(),video.class);
//                startActivity(log);
//            }
//        });



    }
}
