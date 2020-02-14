package com.example.diabeticguard;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Spinner;

import java.util.ArrayList;
import java.util.List;

public class ask_without_picture extends AppCompatActivity {
    private Spinner ingredient;
    private String[] meals = {"Meal","Rice","Pasta","Chicken","Meat","Fish","soup","apple","mango"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ask_without_picture);
        addItemsOnSpinner();
    }
    public void addItemsOnSpinner(){
        ingredient=findViewById(R.id.ingredient);
        ingredient.setAdapter(new ArrayAdapter(this, android.R.layout.simple_spinner_dropdown_item, meals));
    }

}
