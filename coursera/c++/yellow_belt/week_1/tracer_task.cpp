#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

TaskStatus Next(TaskStatus status) {
  return static_cast<TaskStatus>(static_cast<int>(status) + 1);
}

class TeamTasks {
private:
  map<string, TasksInfo> persons;

public:
  const TasksInfo &GetPersonTasksInfo(const string &person) const {
    return persons.at(person);
  }

  void DeleteZeroesTasks(TasksInfo &tasks) {
    vector<TaskStatus> status_to_delete;
    for (const auto &item : tasks) {
      if (item.second == 0) {
        status_to_delete.push_back(item.first);
      }
    }
    for (const TaskStatus &status : status_to_delete){
      tasks.erase(status);
    }

  }

  void AddNewTask(const string &person) {
    ++persons[person][TaskStatus::NEW];
  }

  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string &person,
                                                 int task_count) {
    TasksInfo &current_tasks = persons[person];
    TasksInfo refreshed_tasks, non_refreshed_tasks;

    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = Next(status)) {

      refreshed_tasks[Next(status)] += min(task_count, current_tasks[status]);
      task_count -= refreshed_tasks[Next(status)];
    }
    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = Next(status)) {

      non_refreshed_tasks[status] = current_tasks[status] - refreshed_tasks[Next(status)];
      current_tasks[status] += refreshed_tasks[status] - refreshed_tasks[Next(status)];
    }
    current_tasks[TaskStatus::DONE] += refreshed_tasks[TaskStatus::DONE];

    DeleteZeroesTasks(persons.at(person));
    DeleteZeroesTasks(refreshed_tasks);
    DeleteZeroesTasks(non_refreshed_tasks);

    return {refreshed_tasks, non_refreshed_tasks};
  }
};

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks"
       << ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"
       << ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested"
       << ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}



int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
