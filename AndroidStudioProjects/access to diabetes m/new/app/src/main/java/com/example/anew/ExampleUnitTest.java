package com.example.anew;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class ExampleUnitTest extends AppCompatActivity {
    private TextView tex1;
    private TextView tex2;
    private TextView tex3;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_example_unit_test);
        tex1=findViewById(R.id.textView);
        tex2=findViewById(R.id.textView2);
        tex3=findViewById(R.id.textView3);
        Intent iin=getIntent();

    }

}
