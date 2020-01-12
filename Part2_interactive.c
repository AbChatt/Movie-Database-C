/*
 *  CSC A48 - Winter 2019 - Assignment 1 starter
 * 
 *  (c) 2019 Marzieh Ahmadzadeh and Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This file will test different components of your solution for assignment 1.
 * The actual solution you must implement will be in MDB-c.c.
 * 
 * There is no code for you to implement here!
 * 
 * Let us say that again:
 * 
 * There is NO code for you to implement here.
 * 
 * This file contains a little interface intended to help you test your 
 * solution for part 2 manually, by entering movie review information and
 * carrying out operations from the terminal. 
 * 
 * Using this interface should be part of your process for making sure your
 * assignment solution works well!
 * 
 * Once you have a complete solution, it should pass the entire set of 
 * tests below.
 */

#include "MDB-pro.c"	// <--- This will import your code so we can
			//	use your solution to create a linked
			//	list of movie reviews for testing!

void getTitleStudioYear(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int *year)
{
  // This function reads the movie's name, title, and year from the terminal.
  // It's needed for inserting new reviews, for search, updating, and deletion.
  printf("Please enter the movie's title:\n");
  fgets(title,1024,stdin);
  printf("Please enter the movie's studio:\n");
  fgets(studio,1024,stdin);
  printf("Please enter the movie's year:\n");
  scanf("%d",year);
  getchar();
}

void getBOtotalScore(float *BO_total, int *score)
{
  // This function reads the movie's Box-Office total and its score from 
  // the terminal. Required for inserting a new movie review, or for
  // updating an existing review.
  printf("Please enter the Box Office total:\n");
  scanf("%f",BO_total);
  getchar();
  printf("Please enter the review score:\n");
  scanf("%d",score);
  getchar();
}
			
int main()
{
  ReviewNode *MDB_head=NULL;
  //ReviewNode *temp=NULL;
  int choice=0;
  char title[MAX_STR_LEN];
  char studio[MAX_STR_LEN];
  int year;
  float BO_total;
  float avg;
  int score;
 
  while(choice!=5)
  {
     printf("Please choose one of the following options:\n");
     printf("1 - Insert a new movie review.\n");
     printf("2 - Print out a movie's review list.\n");
     printf("3 - Get a movie's average score.\n");
     printf("4 - Query movies by average score.\n");
     printf("5 - Delete list of reviews and exit.\n");
     scanf("%d",&choice);
     getchar();

     // Read in review information from terminal where needed.
     if (choice>=1&&choice<=3)
     {
       getTitleStudioYear(title,studio,&year);
     }
     if (choice==1)
     {
       getBOtotalScore(&BO_total, &score);
       MDB_head=insertMovieReview(title,studio,year,BO_total,score,MDB_head);
     }
     else if (choice==2)
     {
       printf("Review scores:\n");
       printReviewScores(title,studio,year,MDB_head);
     }
     else if (choice==3)
     {
       avg=getAverageScore(title,studio,year,MDB_head);
       if (avg!=-1)
       {
	 printf("The average score for the movie is %f\n",avg);
       }
       else
       {
	 printf("No such movie in the review database\n");
       }
     }
     else if (choice==4)
     {
       printf("Please input the minimum score you want to look for\n");
       scanf("%d",&score);
       getchar();
       queryReviewsByScore(score,MDB_head);
     }
  }
  
  MDB_head=deleteReviewList(MDB_head);
  printf("Done!\n");
  return 0;
}