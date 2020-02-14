package com.example.diabeticguard;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;

import java.util.ArrayList;
import java.util.List;

public class food extends AppCompatActivity {
Button ask,takepicture;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_food);
        ask=findViewById(R.id.Ask);
        takepicture=findViewById(R.id.takephoto);

       ask.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent log=new Intent(getBaseContext(),ask_without_picture.class);
                startActivity(log);
            }
        });

        takepicture.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent log=new Intent(getBaseContext(),takepicture.class);
                startActivity(log);
            }
        });


    }


}
