//
// Created by xqula on 21.10.2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

void *ChildThread(void *arg);

int main() {
    // handle check
    int handle; // handle
    int schedualing_policy; // schedualing policy field MAIN THREAD
    sched_param schedualing_parameters{}; // struct for schedual priority MAIN THREAD
    pthread_t thread;
    pthread_attr_t thread_attributes;

    cout << "---------- MAIN THREAD BEGIN ----------\n";

    // ---------- OPENING TEXT FILE ----------

    handle = open("/home/xqula/repo/university/linux/lab4/src/txt/in_1.txt", O_RDONLY);

    if (handle == -1) {
        cout << "File's handle HAS NOT BEEN opened by PARENT thread!\n";
        return -1; // end program with error
    }
    cout << "File's handle HAS BEEN opened by PARENT thread! Handle: " << handle << "\n";

    // ---------- CREATING A THREAD (SENDING HANDLE AS A PARAMETER) ----------

    pthread_attr_init(&thread_attributes);
    pthread_create(&thread, &thread_attributes, ChildThread, &handle);
    pthread_join(thread, nullptr);

    // ---------- CURRENT PRIORITY OUTPUT ----------

    cout << "---------- MAIN THREAD INFO ----------\n";
    pthread_getschedparam(pthread_self(), &schedualing_policy, &schedualing_parameters);
    // getting parameters about MAIN thread
    cout << "Current priority: " << schedualing_parameters.sched_priority << "\n"; // current priority

    // ---------- CHECKING ON OPEN/CLOSED FILE (IF OPENED -- FORCIBLY CLOSE) ----------

    if (int handle_check = fcntl(handle, F_GETFD); handle_check != -1) {
        cout << "File's handle HAS NOT BEEN closed by CHILD thread!\n";
        close(handle); // forced closing the file (handle)
        handle_check = fcntl(handle, F_GETFD); // checking handle again

        if (handle_check != -1) {
            cout << "File's handle HAS NOT BEEN closed by PARENT thread!\n";
            return -2; // end program with error
        }
        cout << "File's handle HAS BEEN closed by PARENT thread!\n";
    } else {
        cout << "File's handle HAS BEEN closed by CHILD thread!\n";
    }

    cout << "---------- MAIN THREAD END ----------\n";
    pthread_attr_destroy(&thread_attributes); // cleaning memory w/ destroying thread attributes no loner required

    return 0;
}

// ---------- ChildThread function ----------

void *ChildThread(void *arg) {
    // handle check local
    int local_schedualing_policy; // schedualing policy field
    int local_close = 0;
    // 0 -- child thread DOES NOT CLOSE the handle, 1 -- chiled thread CLOSES the handle, other -- DOES NOT CLOSE by default
    ssize_t local_buffer_counter = -1; // number of bytes read (-1 is for begin, 0 is for ending loop)
    const int local_handle = *static_cast<int *>(arg); // handle of opened file
    sched_param local_schedualing_parameters{}; // struct for schedual priority

    cout << "---------- CHILD THREAD BEGIN ----------\n";

    cout << "Close the handle by child process (0 -- don't close, 1 -- close, other -- don't close)?\n";
    // close handle by child thread or not
    cin >> local_close; // user's choice

    pthread_getschedparam(pthread_self(), &local_schedualing_policy, &local_schedualing_parameters);
    // getting parameters about CHILD thread

    // ---------- SCHEDUALING POLICY, CURRENT, MIN & MAX PRIORITY, FILE OUTPUT ----------

    cout << "---------- CHILD THREAD INFO ----------\n"
            << "Schedualing policy: " // schedualing policy
            << (local_schedualing_policy == SCHED_FIFO ? to_string(local_schedualing_policy) + " -- SCHED_FIFO" : "")
            << (local_schedualing_policy == SCHED_RR ? to_string(local_schedualing_policy) + " -- SCHED_RR" : "")
            << (local_schedualing_policy == SCHED_OTHER
                    ? to_string(local_schedualing_policy) + " -- SCHED_OTHER"
                    : "") << "\n"
            << "Current priority: " << local_schedualing_parameters.sched_priority << "\n" // current priority
            << "Minimal priority: " << sched_get_priority_min(local_schedualing_policy) << "\n" // minimal priority
            << "Maximal priority: " << sched_get_priority_max(local_schedualing_policy) << "\n" // maximal priority
            << "File:\n" // file output
            << "---------- BEGIN OF FILE ----------\n";
    while (local_buffer_counter != 0) // 0 means no bytes to read
    {
        char local_buffer[80];
        constexpr size_t n = sizeof(local_buffer);
        local_buffer_counter = read(local_handle, &local_buffer, n);
        local_buffer[local_buffer_counter] = '\0';
        cout << local_buffer;
    }
    cout << "\n";
    cout << "---------- END OF FILE ----------\n";

    if (local_close == 0) // handle close chosen actions
    {
        cout << "File's handle SHOULD NOT BE closed by CHILD thread!\n";
    } else if (local_close == 1) {
        cout << "File's handle SHOULD BE closed by CHILD thread!\n";
        close(local_handle);
    } else {
        cout << "File's handle SHOULD NOT BE closed by CHILD thread by default!\n";
    }

    if (const int local_handle_check = fcntl(local_handle, F_GETFD); local_handle_check == -1) // handle close try check
    {
        cout << "File's handle HAS BEEN closed by CHILD thread!\n";
    } else {
        cout << "File's handle HAS NOT BEEN closed by CHILD thread!\n";
    }

    cout << "---------- CHILD THREAD END ----------\n";
    pthread_exit(nullptr); // terminating calling thread, i.e. this CHILD process will be terminated
}
