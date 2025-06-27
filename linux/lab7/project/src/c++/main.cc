#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include <signal.h>
#include <wait.h>

using namespace std;

int main() {
	sigset_t new_mask;
	sigemptyset(&new_mask);
	sigaddset(&new_mask, SIGUSR1);
	sigaddset(&new_mask, SIGUSR2);
	sigaddset(&new_mask, SIGQUIT);
	sigprocmask(SIG_SETMASK, &new_mask, NULL);


	int pipefd[2];

	pid_t cpid1,
			cpid2;

	if (pipe(pipefd) == -1) {
		exit(EXIT_FAILURE);
	}

	cpid1 = fork();

	if (cpid1 == 0) {
		/* Child1 */
		close(pipefd[1]);

		execl("exec1","exec1", "out1.txt", &pipefd[0], NULL);

		close(pipefd[0]);
		_exit(EXIT_SUCCESS);

	}
	else {
		/* Parent */

		cpid2 = fork();

		if (cpid2 == 0) {
			/* Child2 */
			close(pipefd[1]);

			execl("exec2","exec2", "out2.txt", &pipefd[0], NULL);

			close(pipefd[0]);
			_exit(EXIT_SUCCESS);
		}
		else {
			/* Parent */
			cout<<"Parent"<<endl;
			close(pipefd[0]);

			ifstream file1("in.txt");
			if (file1.is_open()) {
				string s;
				while(getline(file1, s)){
					write(pipefd[1], &s[0], strlen(s.c_str()));
					cout<<"PARENT пишет:" << s << endl;
				}
				file1.close();
			}

			kill(cpid1, SIGQUIT);
			kill(cpid2, SIGQUIT);

			close(pipefd[1]);
			int st1, st2;
			// waitpid(cpid1, &st1, 0);
			// waitpid(cpid2, &st2, 0);
			exit(EXIT_SUCCESS);
		}
	}

	return 0;
}
