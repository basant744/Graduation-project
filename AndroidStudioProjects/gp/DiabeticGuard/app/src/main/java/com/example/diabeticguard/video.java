package com.example.diabeticguard;

import androidx.appcompat.app.AppCompatActivity;

import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.MediaController;
import android.widget.VideoView;

public class video extends AppCompatActivity {
    VideoView video;
    Button play;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_video);
        video=findViewById(R.id.video);
        play=findViewById(R.id.play);
        play.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                MediaController m = new MediaController(video.this);
                video.setMediaController(m);

                String path ="android.resource://com.example.animation/"+R.raw.videoo;
               Uri u= Uri.parse(path);


                video.setVideoURI(u);

               video.start();
          }
        });


    }
}
