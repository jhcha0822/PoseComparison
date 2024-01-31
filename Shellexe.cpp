//shellexe
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <atlstr.h>
using namespace std;

int main()
{
    //input username
    string username;
    cout << "Input username" << endl;
    cin >> username;

    string mkdir = "mkdir ";
    mkdir.append(username);

    //convert str to char*
    const char* c = mkdir.c_str();

    //transmit to terminal
    system(c);

    string run_openpose = "/C x64\\Release\\OpenPoseDemo.exe --model_pose COCO --num_gpu_start 0 --num_gpu 0 --fps_max 30 --number_people_max 1 --write_json ";
    run_openpose += username;
    cout << run_openpose;
    LPCSTR converted_run_openpose;
    converted_run_openpose = (LPCSTR)run_openpose.c_str();

    //delay for 5 seconds
    //cout << "Delayed for 5 seconds!! Get your position ready to use motion capture." << endl;
    //Sleep(5000);

    //use openpose to get json files
    ShellExecute(NULL, "open", "cmd", converted_run_openpose, "C:\\openpose-master", SW_SHOW);
    return 0;
}