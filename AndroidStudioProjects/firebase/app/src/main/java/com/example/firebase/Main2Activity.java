package com.example.firebase;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class Main2Activity extends AppCompatActivity {
    DatabaseReference zee;
    TextView message;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        zee= FirebaseDatabase.getInstance().getReference().child("read");
        message=findViewById(R.id.textView);
       // writetodata();
        readfromdata();
    }
    public  void writetodata(){

        zee.setValue("hinoha");


    }

    public void readfromdata(){
        zee.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                // This method is called once with the initial value  and again
                // whenever data at this location is updated.
                String value = dataSnapshot.getValue(String.class);
              //  Log.v("kok", "Value is: " + value);
                message.setText(value);
            }

            @Override
            public void onCancelled(DatabaseError error) {
                // Failed to read value
              //  Log.v("kok", "Failed to read value.", error.toException());
            }
        });

    }
}
