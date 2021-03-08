#include <cmath>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <fstream>
#include <stdio.h>
using namespace std;
const int N = 17;
int A[N][N];
int number;//棋子顏色數字
int bemovex, bemovey;//
int longg[1024] = {};//紀錄可移動位置到終點距離 
int movestep[1024][2] = {};//紀錄可移動位置座標 
int miniseat;//最小位置
void readboard(int A[N][N]);
void play();
int main(int argc, char* argv[])
{
	readboard(A);
	number = *argv[1] - '0';
	play();
}
void readboard(int A[N][N])
{
	ifstream file;
	file.open("board.txt");
	int i, j;
	for (j = 0; j < N; j++)
		for (i = 0; i < N; i++)
		{
			file >> A[j][i];
		}
	file.close();
}
void play()
{
	int x[16][3];//紀錄15顆棋的xy座標 
	int stamp = 15;//隨著到達終點的棋子增加 stamp會不斷減少
	int step[6][2] = { 0,-1, 1,-1, -1,0, 1,0, -1,1, 0,1 };//棋子移動6個位置
	//////////////////////////////////////////////
	//棋子顏色 對應到棋子終點 
	int finalx, finaly;
	if (number == 2)
	{
		int ending[15][2] = { 16,4,15,4,15,5,14,4,14,5,14,6,13,4,13,5,13,6,13,7,12,7,12,5,12,6,12,4,12,8 };

		finalx = ending[0][0];
		finaly = ending[0][1];

		if (A[ending[0][0]][ending[0][1]] == 2) {
			finalx = ending[1][0];
			finaly = ending[1][1];
			stamp--;
			A[ending[0][0]][ending[0][1]] = 5;
			if (A[ending[1][0]][ending[1][1]] == 2) {
				finalx = ending[2][0];
				finaly = ending[2][1];
				stamp--;
				A[ending[1][0]][ending[1][1]] = 5;
				if (A[ending[2][0]][ending[2][1]] == 2) {
					finalx = ending[3][0];
					finaly = ending[3][1];
					stamp--;
					A[ending[2][0]][ending[2][1]] = 5;
					if (A[ending[3][0]][ending[3][1]] == 2) {
						finalx = ending[4][0];
						finaly = ending[4][1];
						stamp--;
						A[ending[3][0]][ending[3][1]] = 5;
						if (A[ending[4][0]][ending[4][1]] == 2) {
							finalx = ending[5][0];
							finaly = ending[5][1];
							stamp--;
							A[ending[4][0]][ending[4][1]] = 5;
							if (A[ending[5][0]][ending[5][1]] == 2) {
								finalx = ending[6][0];
								finaly = ending[6][1];
								stamp--;
								A[ending[5][0]][ending[5][1]] = 5;
								if (A[ending[6][0]][ending[6][1]] == 2) {
									finalx = ending[7][0];
									finaly = ending[7][1];
									stamp--;
									A[ending[6][0]][ending[6][1]] = 5;
									if (A[ending[7][0]][ending[7][1]] == 2) {
										finalx = ending[8][0];
										finaly = ending[8][1];
										stamp--;
										A[ending[7][0]][ending[7][1]] = 5;
										if (A[ending[8][0]][ending[8][1]] == 2) {
											finalx = ending[9][0];
											finaly = ending[9][1];
											stamp--;
											A[ending[8][0]][ending[8][1]] = 5;
											if (A[ending[9][0]][ending[9][1]] == 2) {
												finalx = ending[10][0];
												finaly = ending[10][1];
												stamp--;
												A[ending[9][0]][ending[9][1]] = 5;
												if (A[ending[10][0]][ending[10][1]] == 2) {
													finalx = ending[11][0];
													finaly = ending[11][1];
													stamp--;
													A[ending[10][0]][ending[10][1]] = 5;
													if (A[ending[11][0]][ending[11][1]] == 2) {
														finalx = ending[12][0];
														finaly = ending[12][1];
														stamp--;
														A[ending[11][0]][ending[11][1]] = 5;
														if (A[ending[12][0]][ending[12][1]] == 2) {
															finalx = ending[13][0];
															finaly = ending[13][1];
															stamp--;
															A[ending[12][0]][ending[12][1]] = 5;
															if (A[ending[13][0]][ending[13][1]] == 2) {
																finalx = ending[14][0];
																finaly = ending[14][1];
																stamp--;
																A[ending[13][0]][ending[13][1]] = 5;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (number == 3)
	{
		int ending[15][2] = { 4,16,4,15,5,15,4,14,5,14,6,14,4,13,5,13,6,13,7,13,7,12,5,12,6,12,4,12,8,12 };

		finalx = ending[0][0];
		finaly = ending[0][1];

		if (A[ending[0][0]][ending[0][1]] == 3) {
			finalx = ending[1][0];
			finaly = ending[1][1];
			stamp--;
			A[ending[0][0]][ending[0][1]] = 5;
			if (A[ending[1][0]][ending[1][1]] == 3) {
				finalx = ending[2][0];
				finaly = ending[2][1];
				stamp--;
				A[ending[1][0]][ending[1][1]] = 5;
				if (A[ending[2][0]][ending[2][1]] == 3) {
					finalx = ending[3][0];
					finaly = ending[3][1];
					stamp--;
					A[ending[2][0]][ending[2][1]] = 5;
					if (A[ending[3][0]][ending[3][1]] == 3) {
						finalx = ending[4][0];
						finaly = ending[4][1];
						stamp--;
						A[ending[3][0]][ending[3][1]] = 5;
						if (A[ending[4][0]][ending[4][1]] == 3) {
							finalx = ending[5][0];
							finaly = ending[5][1];
							stamp--;
							A[ending[4][0]][ending[4][1]] = 5;
							if (A[ending[5][0]][ending[5][1]] == 3) {
								finalx = ending[6][0];
								finaly = ending[6][1];
								stamp--;
								A[ending[5][0]][ending[5][1]] = 5;
								if (A[ending[6][0]][ending[6][1]] == 3) {
									finalx = ending[7][0];
									finaly = ending[7][1];
									stamp--;
									A[ending[6][0]][ending[6][1]] = 5;
									if (A[ending[7][0]][ending[7][1]] == 3) {
										finalx = ending[8][0];
										finaly = ending[8][1];
										stamp--;
										A[ending[7][0]][ending[7][1]] = 5;
										if (A[ending[8][0]][ending[8][1]] == 3) {
											finalx = ending[9][0];
											finaly = ending[9][1];
											stamp--;
											A[ending[8][0]][ending[8][1]] = 5;
											if (A[ending[9][0]][ending[9][1]] == 3) {
												finalx = ending[10][0];
												finaly = ending[10][1];
												stamp--;
												A[ending[9][0]][ending[9][1]] = 5;
												if (A[ending[10][0]][ending[10][1]] == 3) {
													finalx = ending[11][0];
													finaly = ending[11][1];
													stamp--;
													A[ending[10][0]][ending[10][1]] = 5;
													if (A[ending[11][0]][ending[11][1]] == 3) {
														finalx = ending[12][0];
														finaly = ending[12][1];
														stamp--;
														A[ending[11][0]][ending[11][1]] = 5;
														if (A[ending[12][0]][ending[12][1]] == 3) {
															finalx = ending[13][0];
															finaly = ending[13][1];
															stamp--;
															A[ending[12][0]][ending[12][1]] = 5;
															if (A[ending[13][0]][ending[13][1]] == 3) {
																finalx = ending[14][0];
																finaly = ending[14][1];
																stamp--;
																A[ending[13][0]][ending[13][1]] = 5;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (number == 4)
	{
		int ending[15][2] = { 4,4,5,4,4,5,6,4,5,5,4,6,7,4,6,5,5,6,4,7,7,5,5,7,6,6,8,4,4,8 };

		finalx = ending[0][0];
		finaly = ending[0][1];

		if (A[ending[0][0]][ending[0][1]] == 4) {
			finalx = ending[1][0];
			finaly = ending[1][1];
			stamp--;
			A[ending[0][0]][ending[0][1]] = 5;
			if (A[ending[1][0]][ending[1][1]] == 4) {
				finalx = ending[2][0];
				finaly = ending[2][1];
				stamp--;
				A[ending[1][0]][ending[1][1]] = 5;
				if (A[ending[2][0]][ending[2][1]] == 4) {
					finalx = ending[3][0];
					finaly = ending[3][1];
					stamp--;
					A[ending[2][0]][ending[2][1]] = 5;
					if (A[ending[3][0]][ending[3][1]] == 4) {
						finalx = ending[4][0];
						finaly = ending[4][1];
						stamp--;
						A[ending[3][0]][ending[3][1]] = 5;
						if (A[ending[4][0]][ending[4][1]] == 4) {
							finalx = ending[5][0];
							finaly = ending[5][1];
							stamp--;
							A[ending[4][0]][ending[4][1]] = 5;
							if (A[ending[5][0]][ending[5][1]] == 4) {
								finalx = ending[6][0];
								finaly = ending[6][1];
								stamp--;
								A[ending[5][0]][ending[5][1]] = 5;
								if (A[ending[6][0]][ending[6][1]] == 4) {
									finalx = ending[7][0];
									finaly = ending[7][1];
									stamp--;
									A[ending[6][0]][ending[6][1]] = 5;
									if (A[ending[7][0]][ending[7][1]] == 4) {
										finalx = ending[8][0];
										finaly = ending[8][1];
										stamp--;
										A[ending[7][0]][ending[7][1]] = 5;
										if (A[ending[8][0]][ending[8][1]] == 4) {
											finalx = ending[9][0];
											finaly = ending[9][1];
											stamp--;
											A[ending[8][0]][ending[8][1]] = 5;
											if (A[ending[9][0]][ending[9][1]] == 4) {
												finalx = ending[10][0];
												finaly = ending[10][1];
												stamp--;
												A[ending[9][0]][ending[9][1]] = 5;
												if (A[ending[10][0]][ending[10][1]] == 4) {
													finalx = ending[11][0];
													finaly = ending[11][1];
													stamp--;
													A[ending[10][0]][ending[10][1]] = 5;
													if (A[ending[11][0]][ending[11][1]] == 4) {
														finalx = ending[12][0];
														finaly = ending[12][1];
														stamp--;
														A[ending[11][0]][ending[11][1]] = 5;
														if (A[ending[12][0]][ending[12][1]] == 4) {
															finalx = ending[13][0];
															finaly = ending[13][1];
															stamp--;
															A[ending[12][0]][ending[12][1]] = 5;
															if (A[ending[13][0]][ending[13][1]] == 4) {
																finalx = ending[14][0];
																finaly = ending[14][1];
																stamp--;
																A[ending[13][0]][ending[13][1]] = 5;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//////////////////////////////////////////////
	//紀錄15顆棋子 
	int k = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] == number)
			{
				x[k][1] = i;
				x[k][2] = j;
				k++;
			}
		}
	}
	////////////////////////////////////////////////
	//記錄所有可動空白位置
	int n = 1;//紀錄所記下位置的編號
	int min = 1000;
	int miniseat;//miniseat紀錄最短長度位置編號
	for (int q = 1; q <= stamp; q++)
	{
		if (A[x[q][1] + step[0][0]][x[q][2] + step[0][1]] == 1)//走1號位 
		{
			longg[n] = (pow((x[q][1] + step[0][0]) - finalx, 2) + pow((x[q][2] + step[0][1]) - finaly, 2));
			movestep[n][0] = x[q][1] + step[0][0];
			movestep[n][1] = x[q][2] + step[0][1];
			if (min > longg[n])//取最小長度編號
			{
				min = longg[n];
				miniseat = n;
			}
			n++;
		}
		if (A[x[q][1] + step[1][0]][x[q][2] + step[1][1]] == 1)//走2號位 
		{
			longg[n] = (pow((x[q][1] + step[1][0]) - finalx, 2) + pow((x[q][2] + step[1][1]) - finaly, 2));
			movestep[n][0] = x[q][1] + step[1][0];
			movestep[n][1] = x[q][2] + step[1][1];
			if (min > longg[n])//取最小長度編號
			{
				min = longg[n];
				miniseat = n;
			}
			n++;
		}
		if (A[x[q][1] + step[2][0]][x[q][2] + step[2][1]] == 1)//走3號位 
		{
			longg[n] = (pow((x[q][1] + step[2][0]) - finalx, 2) + pow((x[q][2] + step[2][1]) - finaly, 2));
			movestep[n][0] = x[q][1] + step[2][0];
			movestep[n][1] = x[q][2] + step[2][1];
			if (min > longg[n])//取最小長度編號
			{
				min = longg[n];
				miniseat = n;
			}
			n++;
		}
		if (A[x[q][1] + step[3][0]][x[q][2] + step[3][1]] == 1)//走4號位 
		{
			longg[n] = (pow((x[q][1] + step[3][0]) - finalx, 2) + pow((x[q][2] + step[3][1]) - finaly, 2));
			movestep[n][0] = x[q][1] + step[3][0];
			movestep[n][1] = x[q][2] + step[3][1];
			if (min > longg[n])//取最小長度編號
			{
				min = longg[n];
				miniseat = n;
			}
			n++;
		}
		if (A[x[q][1] + step[4][0]][x[q][2] + step[4][1]] == 1)//走5號位 
		{
			longg[n] = (pow((x[q][1] + step[4][0]) - finalx, 2) + pow((x[q][2] + step[4][1]) - finaly, 2));
			movestep[n][0] = x[q][1] + step[4][0];
			movestep[n][1] = x[q][2] + step[4][1];
			if (min > longg[n])//取最小長度編號
			{
				min = longg[n];
				miniseat = n;
			}
			n++;
		}
		if (A[x[q][1] + step[5][0]][x[q][2] + step[5][1]] == 1)//走6號位 
		{
			longg[n] = (pow((x[q][1] + step[5][0]) - finalx, 2) + pow((x[q][2] + step[5][1]) - finaly, 2));
			movestep[n][0] = x[q][1] + step[5][0];
			movestep[n][1] = x[q][2] + step[5][1];
			if (min > longg[n])//取最小長度編號
			{
				min = longg[n];
				miniseat = n;
			}
			n++;
		}
	}
	/////////////////////////////////////////////////////////////////////////////
	//掃移動到的位置附近的 原棋子 
	int bemovex = 0, bemovey = 0;
	if (number == 2) {

		if (A[movestep[miniseat][0] + step[4][0]][movestep[miniseat][1] + step[4][1]] == 2)//5號位 
		{
			bemovex = movestep[miniseat][0] + step[4][0];
			bemovey = movestep[miniseat][1] + step[4][1];
		}
		else if (A[movestep[miniseat][0] + step[5][0]][movestep[miniseat][1] + step[5][1]] == 2)//6號位 
		{
			bemovex = movestep[miniseat][0] + step[5][0];
			bemovey = movestep[miniseat][1] + step[5][1];
		}
		else if (A[movestep[miniseat][0] + step[2][0]][movestep[miniseat][1] + step[2][1]] == 2)//3號位 
		{
			bemovex = movestep[miniseat][0] + step[2][0];
			bemovey = movestep[miniseat][1] + step[2][1];
		}
		else if (A[movestep[miniseat][0] + step[3][0]][movestep[miniseat][1] + step[3][1]] == 2)//4號位 
		{
			bemovex = movestep[miniseat][0] + step[3][0];
			bemovey = movestep[miniseat][1] + step[3][1];
		}
		else if (A[movestep[miniseat][0] + step[0][0]][movestep[miniseat][1] + step[0][1]] == 2)//1號位 
		{
			bemovex = movestep[miniseat][0] + step[0][0];
			bemovey = movestep[miniseat][1] + step[0][1];
		}
		else if (A[movestep[miniseat][0] + step[1][0]][movestep[miniseat][1] + step[1][1]] == 2)//2號位 
		{
			bemovex = movestep[miniseat][0] + step[1][0];
			bemovey = movestep[miniseat][1] + step[1][1];
		}
	}

	if (number == 3) {

		if (A[movestep[miniseat][0] + step[4][0]][movestep[miniseat][1] + step[4][1]] == 3)//5號位 
		{
			bemovex = movestep[miniseat][0] + step[4][0];
			bemovey = movestep[miniseat][1] + step[4][1];
		}
		else if (A[movestep[miniseat][0] + step[5][0]][movestep[miniseat][1] + step[5][1]] == 3)//6號位 
		{
			bemovex = movestep[miniseat][0] + step[5][0];
			bemovey = movestep[miniseat][1] + step[5][1];
		}
		else if (A[movestep[miniseat][0] + step[2][0]][movestep[miniseat][1] + step[2][1]] == 3)//3號位 
		{
			bemovex = movestep[miniseat][0] + step[2][0];
			bemovey = movestep[miniseat][1] + step[2][1];
		}
		else if (A[movestep[miniseat][0] + step[3][0]][movestep[miniseat][1] + step[3][1]] == 3)//4號位 
		{
			bemovex = movestep[miniseat][0] + step[3][0];
			bemovey = movestep[miniseat][1] + step[3][1];
		}
		else if (A[movestep[miniseat][0] + step[0][0]][movestep[miniseat][1] + step[0][1]] == 3)//1號位 
		{
			bemovex = movestep[miniseat][0] + step[0][0];
			bemovey = movestep[miniseat][1] + step[0][1];
		}
		else if (A[movestep[miniseat][0] + step[1][0]][movestep[miniseat][1] + step[1][1]] == 3)//2號位 
		{
			bemovex = movestep[miniseat][0] + step[1][0];
			bemovey = movestep[miniseat][1] + step[1][1];
		}

	}

	if (number == 4) {
		if (A[movestep[miniseat][0] + step[5][0]][movestep[miniseat][1] + step[5][1]] == 4)//6號位 
		{
			bemovex = movestep[miniseat][0] + step[5][0];
			bemovey = movestep[miniseat][1] + step[5][1];
		}
		else if (A[movestep[miniseat][0] + step[3][0]][movestep[miniseat][1] + step[3][1]] == 4)//4號位 
		{
			bemovex = movestep[miniseat][0] + step[3][0];
			bemovey = movestep[miniseat][1] + step[3][1];
		}
		else if (A[movestep[miniseat][0] + step[4][0]][movestep[miniseat][1] + step[4][1]] == 4)//5號位 
		{
			bemovex = movestep[miniseat][0] + step[4][0];
			bemovey = movestep[miniseat][1] + step[4][1];
		}
		else if (A[movestep[miniseat][0] + step[2][0]][movestep[miniseat][1] + step[2][1]] == 4)//3號位 
		{
			bemovex = movestep[miniseat][0] + step[2][0];
			bemovey = movestep[miniseat][1] + step[2][1];
		}
		else if (A[movestep[miniseat][0] + step[0][0]][movestep[miniseat][1] + step[0][1]] == 4)//1號位 
		{
			bemovex = movestep[miniseat][0] + step[0][0];
			bemovey = movestep[miniseat][1] + step[0][1];
		}
		else if (A[movestep[miniseat][0] + step[1][0]][movestep[miniseat][1] + step[1][1]] == 4)//2號位 
		{
			bemovex = movestep[miniseat][0] + step[1][0];
			bemovey = movestep[miniseat][1] + step[1][1];
		}

	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 1; i <= stamp; i++) {
		cout << x[i][1] << " " << x[i][2] << endl;
	}
	cout << "1" << endl;
	//"要移動的旗子x" "要移動的旗子y"
	cout << bemovex << " " << bemovey << endl;
	//"移動到的x" "移動到的y"
	cout << movestep[miniseat][0] << " " << movestep[miniseat][1] << endl;

	ofstream file;
	file.open("1072005.txt");
	file << "1" << endl;
	//"要移動的旗子x" "要移動的旗子y"
	file << bemovex << " " << bemovey << endl;
	//"移動到的x" "移動到的y"
	file << movestep[miniseat][0] << " " << movestep[miniseat][1] << endl;
	file.close();