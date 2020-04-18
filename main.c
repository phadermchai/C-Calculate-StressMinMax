#include <stdio.h>  // include standard input output library 
#include <math.h>   // include เพื่อใช้ฟังก์ชั่นยกกำลัง(pow) กับ square root(sqrt) 

float calStressMin(float S_x, float S_y, float T_xy);   //ประกาศฟังก์ชันคำนวนความเค้นต่ำสุด
float calStressMax(float S_x, float S_y, float T_xy);   //ประกาศฟังก์ชันคำนวนความเค้นต่ำสุด

int main()  //ฟังก์ชันการทำงานหลัก
{
    float S_x;      //ประตัวแปรสำหรับรับค่าความเค้นปกติที่หน้าตัด S(x) เป็นประเภท float (ทศนิยม)
    float S_y;      //ประตัวแปรสำหรับรับค่าความเค้นปกติที่จุดวิกฤต S(y)) เป็นประเภท float (ทศนิยม)
    float T_xy;     //ประตัวแปรสำหรับรับค่าความเค้นเฉื่อย S(y)) เป็นประเภท float (ทศนิยม)

    float S_max;    //ประตัวแปรสำหรับเก็บค่าความเค้นสูงสุด S(max)) เป็นประเภท float (ทศนิยม)
    float S_min;    //ประตัวแปรสำหรับเก็บค่าความเค้นต่ำสุด S(min)) เป็นประเภท float (ทศนิยม)
    
    printf("Enter S(x): ");     //แสดงข้อความตอนรับค่า S(x)
    scanf("%f", &S_x);          //รับค่า S(x) จากผู้ใช้
    printf("Enter S(y): ");     //แสดงข้อความตอนรับค่า S(y)
    scanf("%f", &S_y);          //รับค่า S(y) จากผู้ใช้
    printf("Enter T(xy): ");    //แสดงข้อความตอนรับค่า T(xy)
    scanf("%f", &T_xy);         //รับค่า T(xy) จากผู้ใช้
    
    S_max = calStressMax(S_x, S_y, T_xy);   //รับค่าจากฟังก์ชันคำนวนความเค้นสูงสุดใส่ในตัวแปร S_max
    S_min = calStressMin(S_x, S_y, T_xy);   //รับค่าจากฟังก์ชันคำนวนความเค้นต่ำสุดใส่ในตัวแปร S_min
    
    /* แสดงข้อความหลังคำนวนเสร็จแล้วว่า ความเค้นต่ำสุดคือค่าของตัวแปร S_min และความเค้นสูงสุดคือค่าของตัวแปร S_max
    %f คือแสดงแบบทศนิยม */
    printf("Stress min is: %f and Stress max is: %f ", S_min, S_max);
}

//ฟังก์ชันคำนวนความเค้นต่ำสุด
float calStressMin(float S_x, float S_y, float T_xy){
    // คำนวนตามสูตร และ return ออกมาเป็นทศนิยม
    return ((S_x + S_y)/2 ) - sqrt( pow( ( (S_x-S_y)/2),2 ) + pow(T_xy, 2) );   
}

//ฟังก์ชันคำนวนความเค้นต่ำสุด
float calStressMax(float S_x, float S_y, float T_xy){
    // คำนวนตามสูตร และ return ออกมาเป็นทศนิยม
    return ((S_x + S_y)/2 ) + sqrt( pow( ( (S_x-S_y)/2),2 ) + pow(T_xy, 2) );
}
