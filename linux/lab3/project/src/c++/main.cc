#include <sys/types.h>  // process attributes
#include <sys/wait.h>   // pid_t types
#include <unistd.h>     // delay, process attributes

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
  int delay_parent;           // delay seconds f/ parent
  int delay_child_1;          // delay seconds f/ child_1
  int pid_1_status;           // status pid_1
  int pid_2_status;           // status pid_2
  char delay_child_2[10];     // delay seconds f/ child_2 (char f/ sending as
                              // argument)
  char file_name[80];         // output file name
                              // "child1" process, created w/ fork()
  std::ofstream file_stream;  // file stream

  std::cout << "Filename: ";
  std::cin >> file_name;
  std::cout << "Parent, child_1 & child_2 delays (separate space): ";
  std::cin >> delay_parent >> delay_child_1 >> delay_child_2;

  file_stream.open(file_name, std::ofstream::out | std::ofstream::app);
  file_stream << "Parent, child_1 & child_2 delays: " << delay_parent << " "
              << delay_child_1 << " " << delay_child_2 << "\n";
  file_stream.close();

  // making process output w/ if-else statement because of more understandable
  if (const pid_t pid_1 = fork(); pid_1 == -1)  // if unsuccessful
  {
    perror(
        "ERROR w/ \"child_1\" process creating w/ \"fork()\" function");  // creating
                                                                          // error
    exit(1);  // exit code '1' means error w/ "fork()" "child_1"
  } else {
    if (pid_1 == 0)  // if creation successed
    {
      sleep(delay_child_1);  // child_1 delay
      file_stream.open(
          file_name,
          std::ofstream::out | std::ofstream::app);  // file open & write
      file_stream << "\n***CHILD_1***\n\n"
                  << "Process ID (PID): " << getpid() << "\n"
                  << "Parent process ID (PPID): " << getppid() << "\n"
                  << "Session ID (SID): " << getsid(getpid()) << "\n"
                  << "Process group ID (PGID): " << getpgid(getpid()) << "\n"
                  << "[real] User ID (UID): " << getuid() << "\n"
                  << "Effective user ID (EUID): " << geteuid() << "\n"
                  << "[real] Group ID (GID): " << getgid() << "\n"
                  << "Effective group ID (EGID): " << getegid() << "\n";
      file_stream.close();
      exit(EXIT_SUCCESS);  // successful exit
    }
    if (const pid_t pid_2 = vfork(); pid_2 == -1)  // if unsuccessful
    {
      perror("ERROR w/ \"child_2\" process creating w/ \"vfork()\" function");
      exit(2);  // exit code '1' means error w/ "vfork()" "child_2"
    } else {
      if (pid_2 == 0)  // process "child2" can switch to executing another
                       // program stored in a file on disk
      {
        // int execl(const char *path, const char *arg, ...);
        execl("exec", file_name, delay_child_2,
              NULL);         // execute another program and sending arguments
        exit(EXIT_SUCCESS);  // successful exit
      }
      sleep(delay_parent);  // parent delay
      file_stream.open(
          file_name,
          std::ofstream::out | std::ofstream::app);  // file open & write
      file_stream << "\n***PARENT***\n\n"
                  << "Process ID (PID): " << getpid() << "\n"
                  << "Parent process ID (PPID): " << getppid() << "\n"
                  << "Session ID (SID): " << getsid(getpid()) << "\n"
                  << "Process group ID (PGID): " << getpgid(getpid()) << "\n"
                  << "[real] User ID (UID): " << getuid() << "\n"
                  << "Effective user ID (EUID): " << geteuid() << "\n"
                  << "[real] Group ID (GID): " << getgid() << "\n"
                  << "Effective group ID (EGID): " << getegid() << "\n";
      file_stream.close();
      // if use "waitpid", parent process wait for end of each
      // if don't use "waitpid", parent process dies, child process becames
      // orphan and it gets other pid
      waitpid(pid_1, &pid_1_status, 0);  // child_1 waiting f/ correct ending
      waitpid(pid_2, &pid_2_status, 0);  // child_2 waiting f/ correct ending
    }
  }

  return 0;
}