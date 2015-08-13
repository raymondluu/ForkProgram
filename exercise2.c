/* 1. Each process is printing lines. One prints Parent: n.
   The other prints Child: n. The n refers the the numbers 0-9.

   2. It looks like when the program is ran fork()
   creates a child process running along side the parent
   and prints the two lines depending on which process is
   a child and which is a parent then it sleeps for 1 second
   and prints the next line counting up to 9 totaling 10 times.

   3. I don't see much output difference. They seem to be running perfect
   side by side. I did experiment with the sleep() and took it out which then
   printed all the Parent lines then the Child lines versus printing 1 parent 
   then 1 child line and repeat.

   With execv:
   1. The parent process prints lines 10 times while the child class runs 
   execv and runs helloWorld once.

   2. Same as the original program except the child class doesn't run a for
   loop 10 times but only runs it once because of the execv command. After
   playing around with it some more I modified the helloWorld program to run
   a for loop and print 10 times similar to what the parent class is doing.

   3. There is not much output difference when this program is ran multipl
   times.
*/


//exercise2.c

/* Program: Fork Program given in assignment
   Purpose: Exercise 2
   File: exercise2.c
   Programmer: Raymond Luu
   Date: 10/15/2013
   Description: Performs Fork program
*/

/* header with information!
   This code is from Wikipedia: http://en.wikipedia.org/wiki/Fork_%28system_call%29 and will need
   to be tested. Also see: http://pubs.opengroup.org/onlinepubs/9699919799/functions/fork.html.
*/

#include <stdio.h>      /*  printf, stderr, fprintf */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* _exit, fork */
#include <stdlib.h>     /* exit */
#include <errno.h>      /* errno */

/* Function: main
   Uses library: stdio.h,sys/types.h,unistd.h,stdlib.h,errno.h
   Recieves: void
   Returns: int
*/

int main(void)
{
  pid_t  pid;

  /* Output from both the child and the parent process
   * will be written to the standard output,
   * as they both run at the same time.
   */
  pid = fork();

  if (pid == -1)
    {
      /* Error:
       * When fork() returns -1, an error happened
       * (for example, number of processes reached the limit).
       */
      fprintf(stderr, "can't fork, error %d\n", errno);
      exit(EXIT_FAILURE);
    }
  else if (pid == 0)
    {
      /* Child process:
       * When fork() returns 0, we are in
       * the child process.
       */
      int  j;
      for (j = 0; j < 10; j++)
	{
	  // printf("child: %d\n", j);
	  //sleep(1);
	  char *cmd[] = {NULL, NULL, (char *)0};
	  execv("helloWorld2", cmd); // modified helloWorld runs 10 times
	  //execv("helloWorld", cmd);  // original helloWorld runs once
	}
      _exit(0);  /* Note that we do not use exit() */
    }
  else
    {
      /* When fork() returns a positive number, we are in the parent process
       * (the fork return value is the PID of the newly created child process)
       * Again we count up to ten.
       */
      int  i;
      for (i = 0; i < 10; i++)
	{
	  printf("parent: %d\n", i);
	  sleep(1);
	}
      exit(0);
    }
  return 0;
}
