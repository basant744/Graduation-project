package com.example.diabeticguard;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class Main4Activity extends AppCompatActivity {
    AlertDialog.Builder builder;

private Spinner diabetictype;
    @Override

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main4);
        addItemsOnSpinner();
        Button register = findViewById(R.id.register);


        //registration
        builder = new AlertDialog.Builder(this);
        register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                builder.setMessage("please type the email verification code.which you received in your email")
                        .setCancelable(false)

                        .setPositiveButton("VERIFY", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                Toast.makeText(getApplicationContext(),"you have been registered successfully ",
                                        Toast.LENGTH_SHORT).show();
                            }
                        })
                        .setNegativeButton("LATER", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {

                            }
                        })
                       .setNeutralButton("RESEND EMAIL", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                Toast.makeText(getApplicationContext(),"Please check your mail ",
                                        Toast.LENGTH_SHORT).show();
                            }
                        });
                AlertDialog alert = builder.create();
                alert.setTitle("Account Verification");
                alert.show();

            }
        });



    }
    public void addItemsOnSpinner(){
        diabetictype=findViewById(R.id.type);
        List<String> list =new ArrayList<String>();
        list.add("Type I");
        list.add("Type II");
        ArrayAdapter<String> dataadapter =new ArrayAdapter<>(this,android.R.layout.simple_spinner_item,list);
        dataadapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        diabetictype.setAdapter(dataadapter);
    }

}
