package com.example.animation;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.MediaController;
import android.widget.VideoView;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {
   VideoView video;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        video=findViewById(R.id.video);


    }

    public void btn(View view) {
        MediaController m = new MediaController(this);
        video.setMediaController(m);

       String path ="android.resource://com.example.animation/"+R.raw.videoo;

        Uri u= Uri.parse(path);


        video.setVideoURI(u);

        video.start();
    }
}

