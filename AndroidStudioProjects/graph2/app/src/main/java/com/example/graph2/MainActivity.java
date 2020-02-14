package com.example.graph2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.github.mikephil.charting.charts.BarChart;
import com.github.mikephil.charting.data.BarData;
import com.github.mikephil.charting.data.BarDataSet;
import com.github.mikephil.charting.data.BarEntry;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

Button barchartt,pichartt;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        barchartt=findViewById(R.id.bar);
       pichartt=findViewById(R.id.pi);

       barchartt.setOnClickListener(new View.OnClickListener() {
           @Override
           public void onClick(View v) {
               Intent log=new Intent(getBaseContext(),barchart.class);
               startActivity(log);
           }
       });
        pichartt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent log=new Intent(getBaseContext(),pichart.class);
                startActivity(log);
            }
        });


    }
}