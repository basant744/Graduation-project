package com.example.diabeticguard;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    private Handler mHandler = new Handler();
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

mHandler.postDelayed(new Runnable() {
    @Override
    public void run() {
        Intent intent=new Intent(MainActivity.this,Main2Activity.class);
        startActivity(intent);
        finish();
    }
},2000);
    }




}
