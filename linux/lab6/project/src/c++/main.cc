// start program
// ./main <launch period> <number of launches>
// <launch period> -- launch period in seconds (time between every launch)
// <number of launches> -- number of program launches (how many times program will launch)

#include <iostream>
#include <csignal>
#include <sys/wait.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

void processFunction (int local_int); // function for repeat
double finalTime (double local_start_time); // counting final time

int main(int argc, char *argv[])
{
	int number_period = 0; // launch period, 0 by default
	int number_launch = 0; // number of launches, 0 by default
	// parent process start time
	itimerval value{}; // for timer structure, new time set
	itimerval old_value{}; // for timer structure, old timer dropped here
	struct sigaction sigact{};

	number_period = atoi(argv[1]); // convert input data to numeric
	number_launch = atoi(argv[2]); // convert input data to numeric
	if(number_launch == 0) return EXIT_FAILURE;
	//start_time = (double)clock() / CLOCKS_PER_SEC; // measuring the current time

	sigact.sa_handler = processFunction; // setting handling function
	sigemptyset(&sigact.sa_mask); // cleaning "set" from all signals

	sigaddset(&sigact.sa_mask, SIGTSTP); // SIGTSTP signal adding to mask
	sigprocmask(SIG_BLOCK, &sigact.sa_mask, nullptr); // SIGTSTP signal blocking
	sigact.sa_flags = 0; // no flags added
	sigaction(SIGALRM, &sigact, nullptr); // setting responce to SIGALRM signal

	// settings for 1st launch, because time (10 us) will be left very fast
	value.it_value.tv_sec = 0; // setting 0 seconds. only useconds
	value.it_value.tv_usec = 10; // setting 10 useconds for fast timer counting --> faster the signal will be sended

	// setting new interval
	value.it_interval.tv_sec = number_period; // interval s, launch period
	value.it_interval.tv_usec = 0; // interval us, launch period

	setitimer(ITIMER_REAL, &value, &old_value); // ITIMER_REAL means always

	for (int i = 0; i < number_launch; i++)
	{
		const auto start_time = static_cast<double>(clock()) / CLOCKS_PER_SEC; // measuring the current time
		pause(); // SIGALRM signal waiting
		cout << "Parent process' work time (seconds): " << finalTime(start_time) << std::endl;
	}

	return 0;
}

void processFunction (int local_int) // function for repeat
{
	int local_status; // status for "waitpid" func
	double local_start_time = 0; // initilaizing

	if (const pid_t local_pid = fork(); local_pid == 0) // if child is created
	{
		const time_t local_seconds = time (nullptr); // seconds since
		sigset_t local_set; // signal set
		const tm* local_time = localtime (&local_seconds); // time date
		local_start_time = static_cast<double>(clock()) / CLOCKS_PER_SEC; // counting current time since starting program

		sigemptyset(&local_set); // setting emty signal set

		cout << "Child process' PID: " << getpid() << "\n"; // get child process' parent ID
		cout << "Parent process' work start time: " << asctime(local_time); //<< "\n";

		sigaddset(&local_set, SIGTSTP); // adding signal SIGTSTP (anti ctrl-z) to the current process
		sigprocmask(SIG_BLOCK, &local_set, nullptr); // adding blocked signals to the set, SIG_BLOCK means blocked signals are current set + set argument in function

		exit(EXIT_SUCCESS);
	}
	else // else if it is not child or child is not created
	{
		waitpid(local_pid, &local_status, 0); // wait until child is terminate its work
		cout << "Child process' work time (seconds): " << finalTime(local_start_time) << "\n"; // cout child process time
	}
}

double finalTime (const double local_start_time) // counting current time since starting prohram & last function
{
	const auto local_end_time = static_cast<double>(clock()) / CLOCKS_PER_SEC;
	return local_end_time - local_start_time;
}