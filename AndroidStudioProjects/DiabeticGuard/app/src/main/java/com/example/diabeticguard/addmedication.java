package com.example.diabeticguard;

import androidx.appcompat.app.AppCompatActivity;

import android.app.DatePickerDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.TextView;

import java.util.Calendar;

public class addmedication extends AppCompatActivity {
    boolean first = true;
    private String[] meals = {"Select category","before breakfast","after breakfast","before lunch","after lunch","before dinner","after dinner","before exercise","after exercise"};
    private Spinner category;

    DatePickerDialog dp;
    int year;
    int month;
    int day;
    Calendar cal;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_addmedication);
        category = findViewById(R.id.category);

        category.setAdapter(new ArrayAdapter(this, android.R.layout.simple_spinner_dropdown_item, meals));
        TextView text= findViewById(R.id.tdate);
        Button button=findViewById(R.id.bdate);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                cal=Calendar.getInstance();
                year=cal.get(Calendar.YEAR);
                month=cal.get(Calendar.MONTH);
                day=cal.get(Calendar.DAY_OF_MONTH);








            }
        });
    }
}
