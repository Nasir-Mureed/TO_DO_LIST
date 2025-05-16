#ifndef	TASK_H
#define TASK_H
#include<iostream>
using namespace std;
class Task
{
	string title;
	string discription;
	int priority;
	string date;
	bool isValidPriority(int prior);
	static void input(string& s);
public:
	Task();
	Task(string tit, string dis, string dat, int prior);
	Task(const Task& t);
	Task& operator =(const Task& t);
	~Task();
	void setTitle(const string& s);
	void setDiscription(const string& d);
	void setPriority(int p);
	void setDate(const string& d);
	string getTitle() const;
	string getDiscription() const;
	int getPriority() const;
	string getDate() const;
	void displayTask() const;
	void inputTask();
};
#endif