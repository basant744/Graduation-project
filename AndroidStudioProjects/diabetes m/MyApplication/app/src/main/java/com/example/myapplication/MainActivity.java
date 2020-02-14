package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import com.diabetesm.addons.api.DiabetesAppConnection;

public class MainActivity extends AppCompatActivity {
    private TextView mResult;
    private Button mPushData;
    private Button mReadData;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mReadData = (Button) findViewById(R.id.read_data);
        mPushData = (Button) findViewById(R.id.push_data);

        final DiabetesAppConnection diaConnection = new DiabetesAppConnection(MainActivity.this);

        DiabetesAppConnection.DiabetesMCheck checkStatus = diaConnection.checkDiabetesMApp();
        if (checkStatus != DiabetesAppConnection.DiabetesMCheck.OK) {
            //update UI id Diabetes:M doesn't support this API or is not installed
            mReadData.setEnabled(false);
            mPushData.setEnabled(false);
            String message = checkStatus == DiabetesAppConnection.DiabetesMCheck.NOT_FOUND ?
                    "Missing Diabetes:M app!" :
                    "Incompatible Diabetes:M version. Must be 5.0.5 or above!";
            mResult.setText(message);
            return;
        }
    }
}
