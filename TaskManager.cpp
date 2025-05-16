#include"TaskManager.h"
#include"Task.h"
#include<iostream>
using namespace std;

TaskManager::TaskManager():noOfTasks(0),taskList(nullptr)
{ }
TaskManager::TaskManager(const Task& t, int count)
{ 
	taskList = new Task[count];
	for (int i = 0;i < count;i++)
		taskList[i] = t;
	noOfTasks = count;
}
TaskManager::TaskManager(const TaskManager& taskM)
{
	*this = taskM;
}
TaskManager& TaskManager::operator =(const TaskManager& taskM)
{
	this->~TaskManager();
	noOfTasks = taskM.noOfTasks;
	taskList = new Task[noOfTasks];
	for (int i = 0;i < noOfTasks;i++)
		taskList[i] = taskM.taskList[i];
	return *this;
}
TaskManager::~TaskManager()
{
	if (this->noOfTasks>0)
	{
		for (int i = noOfTasks-1;i >=0;i--)
			taskList[i].~Task();
		noOfTasks = 0;
		taskList = nullptr;
	}
}
int TaskManager::askToPrompt()
{
	int option;
	cout << "\n\t1_Add new task\n\t2_View all tasks\n\t3_Filter by priority\n\t4_Delete task by title\n\t5_Exit\n\nEnter operation Number to execute:";
	cin >> option;
	return option;
}
void TaskManager::reSize(int newSize)
{
	TaskManager temp;
	temp.taskList = new Task[newSize];
	temp.noOfTasks = newSize;
	for (int i = 0;i < noOfTasks;i++)
		temp.taskList[i] = taskList[i];
	this->~TaskManager();
	*this = temp;
}
void TaskManager::display() const
{
	cout << "\nAll Tasks:\n\nTitle       Discription        Date       Priority\n\n";
	for (int i = 0;i < noOfTasks;i++)
		taskList[i].displayTask();
	if (noOfTasks == 0)
		cout << "No Task is Avaible\n";
	cout << "\n";
}
void TaskManager::displaySamePriorityTasks() const
{
	int x,c=0;
	cout << "Enter Priority number to display Tasks of That Priority:";
	cin >> x;
	cout << "\nTasks of " << x << " Priority :\n";
	for (int i = 0;i < noOfTasks;i++)
	{
		if (taskList[i].getPriority() == x)
		{
			taskList[i].displayTask();
			c++;
		}
	}
	if (c == 0)
		cout << "No Task of Required priority is Avaible: \n";
	cout << "\n";
	
}
void TaskManager::removeTask()
{
	string s;
	cout << "Enter Title of Task You want to delete :";
	cin >> s;
	int i;
	for ( i = 0;i < noOfTasks;i++)
	{
		if (taskList[i].getTitle() == s)
		{
			break;
		}
	}
	for (;i < noOfTasks-1;i++)
	{
		taskList[i] = taskList[i + 1];
	}
	noOfTasks--;
}
void TaskManager::userInterface()
{
	cout << "\n\t\t\t\tWELCOME TO THE TO_DO_LIST\n";
	int loop=1, count = 0;
	do
	{
		int option = askToPrompt();
		switch (option)
		{
		case 1:
			if (count == noOfTasks)
			{
				reSize(count+1);// TaskList

			}
			taskList[count].inputTask();
			count++;
			break;
		case 2:
			display();
			break;
		case 3:
			displaySamePriorityTasks();
			break;
		case 4:
			removeTask();
			count--;
			break;
		case 5:
			loop = -1;
			break;
		default:
			break;
		}
	} while (loop > 0);
}