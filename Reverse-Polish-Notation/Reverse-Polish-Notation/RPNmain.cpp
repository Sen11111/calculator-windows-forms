#include "pch.h"
#include "HeaderExport.h"
#include <iostream>
#include <string>
#include <cmath>

float RPN(char vr[]);
float calculating(char* OPZSTR, int len);

float RPN(char vr[]) {


	int i = 0, s = 0, e = 0;
	char stek[100], exit[100];

	for (i = 0; vr[i] != '\0'; i++)
		switch (vr[i]) {

			case '+':
				while ((s != 0) && (stek[s - 1] != '(')) {
					exit[e] = stek[s - 1];
					e++;
					s--;
				}
				stek[s] = '+';
				s++;
				break;

			case '-':
				while ((s != 0) && (stek[s - 1] != '(')) {
					exit[e] = stek[s - 1];
					e++;
					s--;
				}
				stek[s] = '-';
				s++;
				break;

			case '*':
				while ((s != 0) && (stek[s - 1] != '(') && (stek[s - 1] != '+') && (stek[s - 1] != '-')) {
					exit[e] = stek[s - 1];
					e++;
					s--;
				}
				stek[s] = '*';
				s++;
				break;

			case '/':
				while ((s != 0) && (stek[s - 1] != '(') && (stek[s - 1] != '+') && (stek[s - 1] != '-')) {
					exit[e] = stek[s - 1];
					e++;
					s--;
				}
				stek[s] = '/';
				s++;
				break;

			case '^':
				while ((s != 0) && (stek[s - 1] != '(') && (stek[s - 1] != '+') && (stek[s - 1] != '-')) {
					exit[e] = stek[s - 1];
					e++;
					s--;
				}
				stek[s] = '^';
				s++;
				break;

			case '%':
				while ((s != 0) && (stek[s - 1] != '(') && (stek[s - 1] != '+') && (stek[s - 1] != '-')) {
					exit[e] = stek[s - 1];
					e++;
					s--;
				}
				stek[s] = '%';
				s++;
				break;

			case 's':
				while ((s != 0) && (stek[s - 1] != '(') && (stek[s - 1] != '+') && (stek[s - 1] != '-')) {
					exit[e] = stek[s - 1];
					e++;
					s--;
				}
				stek[s] = 's';
				s++;
				break;

			case '(':
			{
				stek[s] = '(';
				s++;
				break;
			}

			case ')':
				while ((stek[s - 1] != '(') && (s != 0)) {
					exit[e] = stek[s - 1];
					e++;
					s--;
				}
				stek[s - 1] = ' ';
				s--;
				break;

			default:
			{
				exit[e] = vr[i];
				e++;
				if ((vr[i + 1] == '+') ||
					(vr[i + 1] == '-') ||
					(vr[i + 1] == '*') ||
					(vr[i + 1] == '^') ||
					(vr[i + 1] == '%') ||
					(vr[i + 1] == 's') ||
					(vr[i + 1] == '/') ||
					(vr[i + 1] == '(') ||
					(vr[i + 1] == ')')) {
					exit[e] = ' ';
					e++;
				}
			}
		}

	exit[e] = ' ';
	e++;

	while (s != 0) {
		exit[e] = stek[s - 1];
		e++;
		s--;
	}

	exit[e] = 'x';
	for (i = 0; i < e; i++) {
		std::cout << exit[i];
	}
	float r = calculating(exit, i);
	return r;
}


float calculating(char* OPZSTR, int len) {
	std::string answer;
	float stack[100];
	int sp = 0;

	for (int j = 0; j <= len; j++) {
		char c = OPZSTR[j];
		if (c == 'x') break;
		else if (c == ' ' || c == '\n' || c == NULL) continue;

		else if (c == '+') {
			stack[sp - 2] = stack[sp - 2] + stack[sp - 1];
			sp--;
			continue;
		}

		else if (c == '-') {
			stack[sp - 2] = stack[sp - 2] - stack[sp - 1];
			sp--;
			continue;
		}

		else if (c == '*') {
			stack[sp - 2] = stack[sp - 1] * stack[sp - 2];
			sp--;
			continue;
		}

		else if (c == '/') {
			stack[sp - 2] = stack[sp - 2] / stack[sp - 1];
			sp--;
			continue;
		}
		else if (c == '^') {
			stack[sp - 2] = pow(stack[sp - 2], stack[sp - 1]);
			sp--;
			continue;
		}
		else if (c == '%') {
			stack[sp - 2] = fmod(stack[sp - 2], stack[sp - 1]);
			sp--;
			continue;
		}
		else if (c == 's') {
			stack[sp - 2] = pow(stack[sp - 2], 1 / stack[sp - 1]);
			sp--;
			continue;
		}

		else {
			for (int y = j; y < len; y++) {
				if (isdigit(OPZSTR[y]) || OPZSTR[y] == ',') {
					answer += OPZSTR[y];
				}
				else {
					j = y;
					break;
				}
			}
			stack[sp] = stof(answer);
			sp++;
			answer.clear();
		}
	}
	return stack[sp - 1];
}