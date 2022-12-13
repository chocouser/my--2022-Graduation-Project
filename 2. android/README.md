# Realtime Database에서 이미지 저장하기
 
1. 파이어베이스에서 저장된 이미지 String을 가져와 변수에 저장

 

        public void selectFirebase(int index) {
        FirebaseDatabase firebaseDatabase = FirebaseDatabase.getInstance();
        firebaseDatabase.getReference("reviews/" + index).addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                for (DataSnapshot dataSnapshot : snapshot.getChildren()) {
                    if (dataSnapshot.getKey().equals("image")) {
                        String image = dataSnapshot.getValue().toString();
                     ...// 3번에 연결
 
2. String to byte[] 변환

              public static byte[] binaryStringToByteArray(String s) {
        int count = s.length() / 8;
        byte[] b = new byte[count];
        for (int i = 1; i < count; ++i) {
            String t = s.substring((i - 1) * 8, i * 8);
            b[i - 1] = binaryStringToByte(t);
        }
        return b;
    }
   
3. ImageView에 이미지 적용


 
         
                        ... // 1번 아래 연결
                        byte[] b = binaryStringToByteArray(image);
                        ByteArrayInputStream is = new ByteArrayInputStream(b);
                        Drawable reviewImage = Drawable.createFromStream(is, "reviewImage");
                        iv_review_image.setImageDrawable(reviewImage);
                    }
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
    }
 
4. 결과 화면
![사진](https://user-images.githubusercontent.com/101080195/206981688-ea891dba-af9b-4261-890a-9df88da4591f.png)


# Realtime Database에서 이미지 가져오기
1. 파이어베이스에서 저장된 이미지 String을 가져와 변수에 저장
 

        public void selectFirebase(int index) {
        FirebaseDatabase firebaseDatabase = FirebaseDatabase.getInstance();
        firebaseDatabase.getReference("reviews/" + index).addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                for (DataSnapshot dataSnapshot : snapshot.getChildren()) {
                    if (dataSnapshot.getKey().equals("image")) {
                        String image = dataSnapshot.getValue().toString();
                        ... // 3번 코드에서 이어집니다.

2. ImageView에 이미지 적용


                     
                        ... // 1번 코드 아래
                        byte[] b = binaryStringToByteArray(image);
                        ByteArrayInputStream is = new ByteArrayInputStream(b);
                        Drawable reviewImage = Drawable.createFromStream(is, "reviewImage");
                        iv_review_image.setImageDrawable(reviewImage);
                    }
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
    }
  
  3. 결과 화면
  
 
  ![1](https://user-images.githubusercontent.com/101080195/206989473-60020bda-38bf-45a0-a0de-86046e956108.png)


#◾ 앱에 실시간 데이터베이스 SDK 추가

   - dependencies 안에 Firebase database 에 대한 의존성을 추가해줍니다.

plugins {
    id 'com.android.application'
    id 'kotlin-android'
    id 'kotlin-kapt'
    id 'com.google.gms.google-services'
}

...

dependencies {
    ...
    implementation platform('com.google.firebase:firebase-bom:30.0.1')  // Import the BoM for the Firebase platform
    implementation 'com.google.firebase:firebase-database-ktx'  // Declare the dependency for the Realtime Database library
    ...
}

2. RealMainActivity.kt
 

◾# 데이터베이스에 쓰기

// Write a message to the database
val database = Firebase.database("https://....firebasedatabase.app")
val myRef = database.getReference("message")
myRef.setValue(binding.etInput.text.toString())  // 데이터 1개가 계속 수정되는 방식
myRef.push().setValue(binding.etInput.text.toString())  // 데이터가 계속 쌓이는 방식


myRef.setValue ("hi")
 

◾# 데이터베이스에서 읽기

실시간으로 앱 데이터를 읽기 위해 myRef 에 ValueEventListener 를 추가합니다.
이 클래스의 onDataChange() 메서드는 데이터가 변경될 때마다 호출됩니다.
이 클래스의 onCancelled() 메서드는 데이터 읽기에 실패 시 호출됩니다.

// Read from the database
myRef.addValueEventListener(object : ValueEventListener {
   override fun onDataChange(dataSnapshot: DataSnapshot) {  // Called once with the initial value and again
      val value = dataSnapshot.getValue<String>()
      Log.d(TAG, "Value is: $value")
   }
   override fun onCancelled(error: DatabaseError) {  // Failed to read value
      Log.w(TAG, "Failed to read value.", error.toException())  
   }
})

package com.eun.myappkotlin02.realtime

import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.eun.myappkotlin02.LogUtil
import com.eun.myappkotlin02.databinding.ActivityRealMainBinding
import com.eun.myappkotlin02.realtime.chat.view.ChatMainActivity
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.ValueEventListener
import com.google.firebase.database.ktx.database
import com.google.firebase.database.ktx.getValue
import com.google.firebase.ktx.Firebase

class RealMainActivity: AppCompatActivity() {

    companion object {
        const val TAG = "RealMainActivity"
    }

    lateinit var binding: ActivityRealMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityRealMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        
        initView()
    }
    
    
    private fun initView() {
        binding.btnSend.setOnClickListener {

            binding.tvText.append("\n")
            binding.tvText.append(binding.etInput.text)

            // [START write_message]
            // Write a message to the database
            val database = Firebase.database("https://....firebasedatabase.app")
            val myRef = database.getReference("message")

            myRef.setValue(binding.etInput.text.toString())  // 데이터 1개가 계속 수정되는 방식
//            myRef.push().setValue(binding.etInput.text.toString())  // 데이터가 계속 쌓이는 방식
            // [END write_message]

            Log.d(TAG, "myRef :: $myRef")
            binding.etInput.text.clear()

            // [START read_message]
            // Read from the database
            myRef.addValueEventListener(object : ValueEventListener {
                override fun onDataChange(dataSnapshot: DataSnapshot) {
                    // This method is called once with the initial value and again
                    // whenever data at this location is updated.
                    val value = dataSnapshot.getValue<String>()
                    Log.d(TAG, "Value is: $value")
                }

                override fun onCancelled(error: DatabaseError) {
                    // Failed to read value
                    Log.w(TAG, "Failed to read value.", error.toException())
                }
            })
            // [END read_message]

        }
    }
}
 

 

3. activity_real_main.xml
RealMainActicity 에 대한 레이아웃입니다.

<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout 
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:padding="20dp" >

    <TextView
        android:id="@+id/tv_text"
        android:layout_width="0dp"
        android:layout_height="0dp"
        android:padding="20dp"
        android:layout_marginTop="20dp"
        android:layout_marginBottom="20dp"
        android:text="Text"
        android:textSize="18dp"
        android:textColor="@color/black"
        android:background="@color/grey_300"
        app:layout_constraintTop_toTopOf="parent"
        app:layout_constraintBottom_toTopOf="@id/et_input"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintEnd_toEndOf="parent" />
        
    <EditText
        android:id="@+id/et_input"
        android:layout_width="0dp"
        android:layout_height="wrap_content"
        app:layout_constraintTop_toTopOf="parent"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintEnd_toStartOf="@id/btn_send" />

    <Button
        android:id="@+id/btn_send"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="send"
        app:layout_constraintTop_toTopOf="parent"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintStart_toEndOf="@id/et_input"
        app:layout_constraintEnd_toEndOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>


