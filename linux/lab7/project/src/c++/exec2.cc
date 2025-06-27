#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include <signal.h>
#include <wait.h>

using namespace std;

bool pipe_write_is_finished = false; // end of writing indication
void LocalHandler (int local_int);

int main(int argc, char** argv) {
	sigset_t mask;
	sigset_t b_set;
	struct sigaction sigact;
	sigact.sa_handler = &LocalHandler; // setting new handler
	int pipe_read_is_done = 1;
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR2);
	sigaction(SIGQUIT, &sigact, NULL); // changing function reaction to SIGQUIT
	sigaddset(&b_set, SIGQUIT); // SIGQUIT signal add to set
//	sigprocmask(SIG_UNBLOCK, &b_set, NULL);
	int sig;

	ofstream out1;
	char c;
	out1.open(argv[1], ios::app);
	if (!out1.is_open()) {
		cout<<"Не удалось открыть файл."<< endl;
		return EXIT_FAILURE;
	}
	sigwait(&b_set, &sig);
	sigwait(&mask, &sig);
	while((pipe_read_is_done = read(*argv[2], &c, 1)) > 0 || pipe_write_is_finished == false){
        if(pipe_read_is_done > 0){
			out1 << c << endl;
			killpg(0, SIGUSR1);
			sigwait(&mask, &sig);
        }
	}
	killpg(0, SIGUSR1);
	return EXIT_SUCCESS;
}

void LocalHandler (int local_int)
{
	pipe_write_is_finished = true; // pipe writing is finished
}