package com.example.graph2;

import android.graphics.Color;
import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.github.mikephil.charting.charts.PieChart;
import com.github.mikephil.charting.data.BarEntry;
import com.github.mikephil.charting.data.Entry;
import com.github.mikephil.charting.data.PieData;
import com.github.mikephil.charting.data.PieDataSet;
import com.github.mikephil.charting.utils.ColorTemplate;

import java.util.ArrayList;

public class pichart extends AppCompatActivity {
   //PieChart pieChart;

    PieChart pieChart ;
    ArrayList<Entry> entries ;
    ArrayList<String> PieEntryLabels ;
    PieDataSet pieDataSet ;
    PieData pieData ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pichart);
       pieChart = findViewById(R.id.pichart);

       pieChart.setDrawHoleEnabled(true);

       //dayra ely fe elnos
       pieChart.setHoleColor(Color.WHITE);
       //3d effect
       pieChart.setTransparentCircleRadius(61f);

        entries = new ArrayList<>();

        PieEntryLabels = new ArrayList<String>();

        AddValuesToPIEENTRY();

        AddValuesToPieEntryLabels();

        pieDataSet = new PieDataSet(entries, "Gradient");


        pieData = new PieData(PieEntryLabels, pieDataSet);


//lon el ktaba
        pieData.setValueTextSize(15f);
        pieData.setValueTextColor(Color.BLACK);

        pieDataSet.setColors(ColorTemplate.JOYFUL_COLORS);

        pieChart.setData(pieData);

        pieChart.animateY(2000);




    }

    public void AddValuesToPIEENTRY(){

        entries.add(new BarEntry(30f, 0));
        entries.add(new BarEntry(10f, 1));
        entries.add(new BarEntry(8f, 2));
        entries.add(new BarEntry(20f, 3));


    }

    public void AddValuesToPieEntryLabels(){


        PieEntryLabels.add("Checken");
        PieEntryLabels.add("Meat");
        PieEntryLabels.add("Soup");
        PieEntryLabels.add("Rice");


    }
}