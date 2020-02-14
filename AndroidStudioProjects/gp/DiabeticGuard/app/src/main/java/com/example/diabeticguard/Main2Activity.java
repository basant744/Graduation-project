package com.example.diabeticguard;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class Main2Activity extends AppCompatActivity {
    AlertDialog.Builder builder;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        Button login = findViewById(R.id.login);
       Button forget=findViewById(R.id.forgetpass);

       //log in go to data page
       login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent log=new Intent(getBaseContext(),Main3Activity.class);
                startActivity(log);

            }
        });

       //create new account
          Button create =findViewById(R.id.createnewaccount);
          create.setOnClickListener(new View.OnClickListener() {
              @Override
              public void onClick(View view) {
                  Intent createnew =new Intent(getBaseContext(),Main4Activity.class);
                  startActivity(createnew);
              }
          });

         // Alert dialog forget pass
        builder = new AlertDialog.Builder(this);
          forget.setOnClickListener(new View.OnClickListener() {
              @Override
              public void onClick(View view) {
                  builder.setMessage("Please enter the email address you used when creating your account.")
                          .setCancelable(false)
                          .setPositiveButton("SEND RESET EMAIL", new DialogInterface.OnClickListener() {
                              @Override
                              public void onClick(DialogInterface dialogInterface, int i) {
                                  Toast.makeText(getApplicationContext(),"please check yor email",
                                          Toast.LENGTH_SHORT).show();

                              }
                          })
                          .setNegativeButton("CANCEL", new DialogInterface.OnClickListener() {
                              @Override
                              public void onClick(DialogInterface dialogInterface, int i) {

                              }
                          });
                  AlertDialog alert = builder.create();
                  alert.setTitle("Forgot username or password?");
                  alert.show();
              }
          });

    }

}
