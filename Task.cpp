#include"Task.h"
#include<iostream>
using namespace std;
Task::Task():title("Title"),discription("Discription"),priority(1),date("01/01/2025")
{ }
Task::Task(string tit, string dis, string dat, int prior) :title(tit), discription(dis), date(dat)
{ 
	if (isValidPriority(prior))
		priority = prior;
}
bool Task::isValidPriority(int prior)
{
	if (prior <= 0 || prior >= 5)
		return false;
	return true;
}
Task::Task(const Task& t)
{
	*this = t;
}
Task& Task::operator =(const Task& t)
{
	title = t.title;
	discription = t.discription;
	priority = t.priority;
	date = t.date;
	return *this;
}
Task::~Task()
{
	priority = 1;
}
void Task::setTitle(const string& s)
{
	if (!s.empty())
		title = s;
}
void Task::setDiscription(const string& d)
{
	if (!d.empty())
		discription = d;
}
void Task::setPriority(int p)
{
	if (isValidPriority(p))
		priority = p;
}
void Task::setDate(const string& d)
{
	if (!d.empty())
		date = d;
}
string Task::getTitle() const
{
	return title;
}
string Task::getDiscription() const
{
	return discription;
}
int Task::getPriority() const
{
	return priority;
}
string Task::getDate() const
{
	return date;
}
void Task::displayTask() const
{
	cout << title<<" --> "<<discription<<" --> "<<date<<" --> ";
	switch (priority)
	{
	case 1:
		cout << priority<<" [Low]\n";
		break;
	case 2:
		cout << priority << " [Medium]\n";
		break;
	case 3:
		cout << priority << " [High]\n";
		break;
	case 4:
		cout << priority << " [Urgent]\n";
		break;
	default:
		cout << "No Priority\n";
		break;
	}
}
void Task::inputTask()
{
	string temp;
	cout << "Enter Title of Task [Single World] : ";
	cin >> temp;
	cin.ignore();
	setTitle(temp);
	cout << "Enter Discription of Task : ";
	input(temp);
	setDiscription(temp);
	cout << "Enter Due Date of Task : ";
	input(temp);
	setDate(temp);
	int x;
	do
	{
		cout << "Select Priority Number -> \t 1-Low\t 2-Medium\t 3-High\t 4-Urgent : ";
		cin >> x;
	} 
	while (!isValidPriority(x));
	priority = x;
}
void Task::input(string& s)
{
	s.clear();
	char ch;
	while ((ch = cin.get()) != '\n')
	{
		s += ch;
	}
	s.shrink_to_fit();
}