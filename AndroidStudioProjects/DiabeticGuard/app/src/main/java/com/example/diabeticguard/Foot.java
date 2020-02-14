package com.example.diabeticguard;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;

import android.app.PendingIntent;
import android.content.Intent;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.media.RingtoneManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class Foot extends AppCompatActivity {

    private FirebaseDatabase firebaseDatabase = FirebaseDatabase.getInstance();
    private DatabaseReference reff = firebaseDatabase.getReference();
    private DatabaseReference pressure= reff.child("firstpressure:");
    private DatabaseReference temperature = reff.child("secondpressure:");

    public int pre,temp;
    TextView temptxt,pressurtxt;
    ImageView p1color;
    Button green,yellow,care;


    private final String channelid="channel_id";
    private final int notificationid=101;

    private final String channelid1="channel_id1";
    private final int notificationid1=001;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_foot2);

        care=findViewById(R.id.care);


        pressurtxt=findViewById(R.id.pressuretxt);
        temptxt=findViewById(R.id.temptxt);


         p1color=findViewById(R.id.p1color);

if(pre>=86){
    NotificationCompat.Builder builder=new NotificationCompat.Builder(Foot.this,channelid);
    builder.setContentTitle("Diabetic Guard alert");
    builder.setContentText("take care your foot pressure is high");
    builder.setSmallIcon(R.drawable.foot);
    builder.setLargeIcon(BitmapFactory.decodeResource(getResources(), R.drawable.foot));
    // builder .setStyle(new NotificationCompat.BigPictureStyle()
    //.bigPicture(BitmapFactory.decodeResource(getResources(), R.drawable.alert)));
    builder.setPriority(NotificationCompat.PRIORITY_DEFAULT);

    builder.setSound(RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION));
    builder.setVibrate(new long[] {
            500,
            500,
            500,
            500
    });
    builder.setVisibility(NotificationCompat.VISIBILITY_PUBLIC);
    Intent intent = new Intent(Foot.this, Foot.class);
    intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
    PendingIntent pendingIntent = PendingIntent.getActivity(Foot.this, 0, intent, 0);
    builder.setContentIntent(pendingIntent).setAutoCancel(true);
    NotificationManagerCompat manager=NotificationManagerCompat.from(Foot.this);
    manager.notify(notificationid,builder.build());

}

        care.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent=new Intent(Foot.this,daily_care.class);
                startActivity(intent);
            }
        });


    }

    protected void onStart() {
        super.onStart();
        temperature.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {

                String message = dataSnapshot.getValue(String.class);
                temp= Integer.parseInt(message);

                temptxt.setText(message);
                if (temp == 38) {

                    Toast.makeText(getApplicationContext(),"High Temperature ",
                            Toast.LENGTH_LONG).show();


                    NotificationCompat.Builder builder1=new NotificationCompat.Builder(Foot.this,channelid1);
                    builder1.setContentTitle("Diabetic Guard alert");
                    builder1.setContentText("take care your temperature is high");
                    builder1.setSmallIcon(R.drawable.foot);
                    builder1.setLargeIcon(BitmapFactory.decodeResource(getResources(), R.drawable.foot));
                    // builder .setStyle(new NotificationCompat.BigPictureStyle()
                    //.bigPicture(BitmapFactory.decodeResource(getResources(), R.drawable.alert)));
                    builder1.setPriority(NotificationCompat.PRIORITY_DEFAULT);

                    builder1.setSound(RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION));
                    builder1.setVibrate(new long[] {
                            500,
                            500,
                            500,
                            500
                    });
                    builder1.setVisibility(NotificationCompat.VISIBILITY_PUBLIC);
                    Intent intent1 = new Intent(Foot.this, Foot.class);
                    intent1.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
                    PendingIntent pendingIntent1 = PendingIntent.getActivity(Foot.this, 0, intent1, 0);
                    builder1.setContentIntent(pendingIntent1).setAutoCancel(true);
                    NotificationManagerCompat manager1=NotificationManagerCompat.from(Foot.this);
                    manager1.notify(notificationid1,builder1.build());


                }

            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });


        pressure.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {

                String message = dataSnapshot.getValue(String.class);
                pre= Integer.parseInt(message);

                pressurtxt.setText(message);

                if ( pre <= 5) {
                    int value= Color.parseColor("#AAA8A9");
                    p1color.setColorFilter(value);




                }
                else if(pre <= 34 && pre> 6 ){
                    int value= Color.parseColor("#335bff");
                    p1color.setColorFilter(value);
                }

                else if(pre <= 85 && pre >35 ){
                    int value= Color.parseColor("#fe7b07");
                    p1color.setColorFilter(value);

                }
                else{
                    Toast.makeText(getApplicationContext(),"High Pressure ",
                            Toast.LENGTH_SHORT).show();
                    int value= Color.parseColor("#f51506");
                    p1color.setColorFilter(value);



                }

            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });


    }
}
