package com.example.diabeticguard;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ListView;

public class medication extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_medication);

        ImageButton addmedication =findViewById(R.id.addmedication);
        ListView listview=findViewById(R.id.list);
        String[]names={"(Amaryl","Glucotrol","Micronase","Glynase","Diabinese","Orinase","Tolinase","Starlix"};
        ArrayAdapter adapter=new ArrayAdapter(this,android.R.layout.simple_list_item_1,names);
        listview.setAdapter(adapter);

        addmedication.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent=new Intent(medication.this,addmedication.class);
                startActivity(intent);
            }
        });

    }
}
