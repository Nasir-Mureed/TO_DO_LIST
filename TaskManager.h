#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include"Task.h"
class TaskManager
{
	int noOfTasks;
	Task* taskList;
	int askToPrompt();
	void reSize(int newSize);
	void display() const;
	void displaySamePriorityTasks() const;
	void removeTask();
public:
	TaskManager();
	TaskManager(const Task& t, int count);
	TaskManager(const TaskManager& taskM);
	TaskManager& operator =(const TaskManager& taskM);
	~TaskManager();
	void userInterface();
};
#endif
