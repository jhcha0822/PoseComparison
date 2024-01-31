#pragma comment (lib, "lib_json.lib")

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <direct.h>
#include "include/json/json.h"
#include <direct.h>
#include <math.h>

using namespace std;
using namespace Json;

//JSONS파일의 값의 형태지정
struct Cosinoutput {
	double x;
	double y;
	double prob;
	double getX() { return x; }
	double getY() { return y; }
};
std::map<int, Cosinoutput> Cosinoutputs;

struct Cosinoutput1 {
	double x;
	double y;
	double prob;
	double getX() { return x; }
	double getY() { return y; }
};
std::map<int, Cosinoutput1 > Cosinoutputs1;

double cosin(double x1, double y1, double x2, double y2) {
	double length1 = sqrt(pow(x1, 2)) + sqrt(pow(y1, 2));
	double length2 = sqrt(pow(x2, 2)) + sqrt(pow(y2, 2));
	double inner = x1 * x2 + y1 * y2;
	double cosin = inner / (length1 * length2);
	return cosin;
};

double external_cosin(double x1, double y1, double x2, double y2, double x3, double y3) {
	//external_product(외적 계산)
	double x_move = x1 - x2;
	double y_move = y1 - y2;
	double x_standard = x3 - x2;
	double y_standard = y3 - y2;
	double external = (x_standard * y_move) - (x_move * y_standard);
	double R = 2.0;
	if (external >= 0) {
		double result = acos(cosin(x_move, y_move, x_standard, y_standard));
		return result;
	}
	else if (external < 0) {
		double revers_cosin = 6.28378 - acos(cosin(x_move, y_move, x_standard, y_standard));
		return revers_cosin;
	}
}


int main()
{
	vector<double>output;
	int n = 0;
	
	for (int fn = 1; fn <= 1000; fn++)
	{
		//JSONS파일 파싱 반복
		char filename[1000];
		sprintf_s(filename, "openpose/serverfile/%012d_keypoints.json", fn);
		cout << filename << endl;
		Value root;
		ifstream ifs(filename, std::ifstream::in);
		CharReaderBuilder builder;
		builder["collectComments"] = false;

		//JSONS파일 파싱 성공여부 체크
		JSONCPP_STRING errs;
		if (!parseFromStream(builder, ifs, &root, &errs)) {
			std::cout << errs << std::endl;
			break;
		}

		//JSONS파일 파싱후 데이터 map에 추출
		Value Target = root["people"];
		for (ValueIterator it1 = Target.begin(); it1 != Target.end(); ++it1) {
			Value NewTarget = (*it1)["pose_keypoints_2d"];
			for (ValueIterator it2 = NewTarget.begin(); it2 != NewTarget.end();) {
				static int key_id = 0;
				Cosinoutput cur;

				cur.x = (*it2++).asDouble();
				cur.y = (*it2++).asDouble();
				cur.prob = (*it2++).asDouble();

				Cosinoutputs.insert(pair<int, Cosinoutput>(key_id++, cur));
			}
		}

		vector<double> vec;
		for (auto iter: Cosinoutputs) {
			vec.push_back(iter.second.getX());
			vec.push_back(iter.second.getY());
		}

		int pram = 10000; 

		vector<double>ser0 = { pram *vec[0],pram * vec[1] };
		vector<double>ser1 = { pram * vec[2],pram * vec[3] };
		vector<double>ser2 = { pram * vec[4],pram * vec[5] };
		vector<double>ser3 = { pram * vec[6],pram * vec[7] };
		vector<double>ser4 = { pram * vec[8],pram * vec[9] };
		vector<double>ser5 = { pram * vec[10],pram * vec[11] };
		vector<double>ser6 = { pram * vec[12],pram * vec[13] };
		vector<double>ser7 = { pram * vec[14],pram * vec[15] };
		vector<double>ser8 = { pram * vec[16],pram * vec[17] };
		vector<double>ser9 = { pram * vec[18],pram * vec[19] };
		vector<double>ser10 = { pram * vec[20],pram * vec[21] };
		vector<double>ser11 = { pram * vec[22],pram * vec[23] };
		vector<double>ser12 = { pram * vec[24],pram * vec[25] };
		vector<double>ser13 = { pram * vec[26],pram * vec[27] };

		Cosinoutputs.clear();

		//JSONS파일 파싱 반복
		char filenames[1000];
		sprintf_s(filenames, "openpose/livefile
			/%012d_keypoints.json", fn);
		cout << filenames << endl;
		Value roots;
		ifstream ifs2(filenames, std::ifstream::in);
		CharReaderBuilder builders;
		builders["collectComments"] = false;

		//JSONS파일 파싱 성공여부 체크
		JSONCPP_STRING errs2;
		if (!parseFromStream(builders, ifs2, &roots, &errs2)) {
			std::cout << errs2 << std::endl;
			break;
		}

		//JSONS파일 파싱후 데이터 map에 추출
		Value Targets = roots["people"];
		for (ValueIterator it1 = Targets.begin(); it1 != Targets.end(); ++it1) {
			Value NewTargets = (*it1)["pose_keypoints_2d"];
			for (ValueIterator it2 = NewTargets.begin(); it2 != NewTargets.end();) {
				static int key_id = 0;
				Cosinoutput1 cur;

				cur.x = (*it2++).asDouble();
				cur.y = (*it2++).asDouble();
				cur.prob = (*it2++).asDouble();

				Cosinoutputs1.insert(pair<int, Cosinoutput1>(key_id++, cur));
			}
		}

		vector<double> vec1;
		for (auto iter : Cosinoutputs1) {
			vec1.push_back(iter.second.getX());
			vec1.push_back(iter.second.getY());
		}

		vector<double>live0 = { pram * vec1[0],pram * vec1[1] };
		vector<double>live1 = { pram * vec1[2],pram * vec1[3] };
		vector<double>live2 = { pram * vec1[4],pram * vec1[5] };
		vector<double>live3 = { pram * vec1[6],pram * vec1[7] };
		vector<double>live4 = { pram * vec1[8],pram * vec1[9] };
		vector<double>live5 = { pram * vec1[10],pram * vec1[11] };
		vector<double>live6 = { pram * vec1[12],pram * vec1[13] };
		vector<double>live7 = { pram * vec1[14],pram * vec1[15] };
		vector<double>live8 = { pram * vec1[16],pram * vec1[17] };
		vector<double>live9 = { pram * vec1[18],pram * vec1[19] };
		vector<double>live10 = { pram * vec1[20],pram * vec1[21] };
		vector<double>live11 = { pram * vec1[22],pram * vec1[23] };
		vector<double>live12 = { pram * vec1[24],pram * vec1[25] };
		vector<double>live13 = { pram * vec1[26],pram * vec1[27] };



		Cosinoutputs1.clear();


		//server 데이터 angle계산
		double server_cosin0 = external_cosin(ser0[0], ser0[1], ser1[0],ser1[1], ser2[0], ser2[1]);
		double server_cosin1 = external_cosin(ser1[0], ser1[1], ser2[0], ser2[1], ser3[0], ser3[1]);
		double server_cosin2 = external_cosin(ser2[0], ser2[1], ser3[0], ser3[1], ser4[0], ser4[1]);
		double server_cosin3 = external_cosin(ser1[0], ser1[1], ser5[0], ser5[1], ser6[0], ser6[1]);
		double server_cosin4 = external_cosin(ser5[0], ser5[1], ser6[0], ser6[1], ser7[0], ser7[1]);
		double server_cosin5 = external_cosin(ser1[0], ser1[1], ser8[0], ser8[1], ser9[0], ser9[1]);
		double server_cosin6 = external_cosin(ser8[0], ser8[1], ser9[0], ser9[1], ser10[0], ser10[1]);
		double server_cosin7 = external_cosin(ser1[0], ser1[1], ser11[0], ser11[1], ser12[0], ser12[1]);
		double server_cosin8 = external_cosin(ser11[0], ser11[1], ser12[0], ser12[1], ser13[0], ser13[1]);
		/*cout << server_cosin0 << endl;
		cout << server_cosin1 << endl;
		cout << server_cosin2 << endl;
		cout << server_cosin3 << endl;
		cout << server_cosin4 << endl;
		cout << server_cosin5 << endl;
		cout << server_cosin6 << endl;
		cout << server_cosin7 << endl;
		cout << server_cosin8 << endl;*/


		//live 데이터 angle계산
		double live_cosin0 = external_cosin(live0[0], live0[1], live1[0], live1[1], live2[0], live2[1]);
		double live_cosin1 = external_cosin(live1[0], live1[1], live2[0], live2[1], live3[0], live3[1]);
		double live_cosin2 = external_cosin(live2[0], live2[1], live3[0], live3[1], live4[0], live4[1]);
		double live_cosin3 = external_cosin(live1[0], live1[1], live5[0], live5[1], live6[0], live6[1]);
		double live_cosin4 = external_cosin(live5[0], live5[1], live6[0], live6[1], live7[0], live7[1]);
		double live_cosin5 = external_cosin(live1[0], live1[1], live8[0], live8[1], live9[0], live9[1]);
		double live_cosin6 = external_cosin(live8[0], live8[1], live9[0], live9[1], live10[0], ser10[1]);
		double live_cosin7 = external_cosin(live1[0], live1[1], live11[0], live11[1], live12[0], live12[1]);
		double live_cosin8 = external_cosin(live11[0], live11[1], live12[0], live12[1], live13[0], live13[1]);
		/*cout << live_cosin0 << endl;
		cout << live_cosin1 << endl;
		cout << live_cosin2 << endl;
		cout << live_cosin3 << endl;
		cout << live_cosin4 << endl;
		cout << live_cosin5 << endl;
		cout << live_cosin6 << endl;
		cout << live_cosin7 << endl;
		cout << live_cosin8 << endl;*/


		//유사도 계산
		double sim0 = cos(fabs(server_cosin0 - live_cosin0));
		double sim1 = cos(fabs(server_cosin1 - live_cosin1));
		double sim2 = cos(fabs(server_cosin2 - live_cosin2));
		double sim3 = cos(fabs(server_cosin3 - live_cosin3));
		double sim4 = cos(fabs(server_cosin4 - live_cosin4));
		double sim5 = cos(fabs(server_cosin5 - live_cosin5));
		double sim6 = cos(fabs(server_cosin6 - live_cosin6));
		double sim7 = cos(fabs(server_cosin7 - live_cosin7));
		double sim8 = cos(fabs(server_cosin8 - live_cosin8));

		

		
		double avesim = (((sim0)+(sim1) + (sim2) + (sim3) + (sim4) + (sim5) + (sim6) + (sim7) + (sim8) ) / 9) * 100;


		cout << "프레임" << fn << "유사도 : " << avesim << endl;

		output.push_back(avesim);
		cout << "end cycle" << endl; 
		n++;
	}
	cout << n << endl;
	int s;
	double sum = 0;
	for (s = 0; s < n-1; s++) {
		sum = sum + output[s];
	}
	double average = sum / n;

	cout << "평균유사도 : " << average << endl;
	

	if (average >= 82)
		cout << "인증이 완료되었습니다!" << endl;
	else if (average < 82)
		cout << "인증에 실패하였습니다 다시시도해주세요!" << endl;

	return 0;
}