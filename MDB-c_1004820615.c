/*
 *  CSC A48 - Winter 2019 - Assignment 1 starter
 * 
 *  (c) 2019 Marzieh Ahmadzadeh and Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout, and given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. At any point you can bring 
 * questions to your TAs or instructors during office hours. But please
 * remember:
 * 
 * - You should not post any assignment code on Piazza
 * - You should not share any part of your solution in any form
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name): Chatterjee, Abhishek
 * Student Number: 1004820615
 * UTORid: chatt114
 * Your instructor's name is: Francisco J Estrada
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name: Abhishek Chatterjee
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/***************************************************************************/

typedef struct MovieReview_struct
{
    char movie_title[MAX_STR_LEN];
    char movie_studio[MAX_STR_LEN];
    int year;
    float BO_total;
    int score;
} MovieReview;

typedef struct ReviewNode_struct
{
    MovieReview review;
    struct ReviewNode_struct *next;
} ReviewNode;

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates a new, empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to empty values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_review = NULL;

    new_review = (ReviewNode *) calloc(1, sizeof(ReviewNode));

    if (new_review != NULL)
    {
        strcpy(new_review->review.movie_title, "");
        strcpy(new_review->review.movie_studio, "");
        new_review->review.year = -1;
        new_review->review.BO_total = -1;
        new_review->review.score = -1;
        new_review->next = NULL;
    }
    
    return new_review;	// <--- This should change when after you implement your solution
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * In this case, the movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns a pointer to the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    ReviewNode *p = NULL;

    p = head;

    while (p != NULL)
    {
        if (strcmp(p->review.movie_title, title) == 0)
        {
            if (strcmp(p->review.movie_studio, studio) == 0)
            {
                if (p->review.year == year)
                {
                    return p;
                }
            }
        }
        p = p->next;
    }

    return NULL;	// <--- This should change when after you implement your solution
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *at the head* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    ReviewNode *p = NULL;
    ReviewNode *new_review = NULL;

    p = findMovieReview(title, studio, year, head);

    if (p != NULL)
    {
        printf("Sorry, that movie already exists\n");
        return head;
    }

    while (strlen(title) > MAX_STR_LEN - 1 || strlen(title) < 1)
    {
        printf("Invalid length movie title entered. Please enter a movie title that is between 1-1023 characters long\n");
        fgets(title, MAX_STR_LEN, stdin);
    }

    while (strlen(studio) > MAX_STR_LEN - 1 || strlen(studio) < 1)
    {
        printf("Invalid length studio name entered. Please enter a studio name that is between 1-1023 characters long\n");
        fgets(studio, MAX_STR_LEN, stdin);
    }

    while (year < 1920 || year > 2999)
    {
        printf("Invalid year entered. Please enter a year in the range 1920-2999\n");
        scanf("%d", &year);
        getchar();
    }

    while (score < 0 || score > 100)
    {
        printf("Invalid score entered. Please enter a score between 1-100\n");
        scanf("%d", &score);
        getchar();
    }

    new_review = newMovieReviewNode();

    strcpy(new_review->review.movie_title, title);
    strcpy(new_review->review.movie_studio, studio);
    new_review->review.year = year;
    new_review->review.BO_total = BO_total;
    new_review->review.score = score;

    new_review->next = head;
    
    return new_review;	// <--- This should change when after you implement your solution
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the length of the current linked list. This requires
   * list traversal.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
    int count = 0;
    ReviewNode *p = NULL;

    p = head;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;	// <--- This should change when after you implement your solution
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists at this point"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p = NULL;

    p = head;

    while (p != NULL)
    {
        if (strcmp(p->review.movie_title, title) == 0)
        {
            if (strcmp(p->review.movie_studio, studio) == 0)
            {
                if (p->review.year == year)
                {
                    while (score < 0 || score > 100)
                    {
                        printf("Invalid score entered. Please enter a new score between 1-100\n");
                        scanf("%d", &score);
                    }

                    p->review.BO_total = BO_total;
                    p->review.score = score;
                }
            }
        }
        p = p->next;
    }

    printf("Sorry, no such movie exists at this point\n");

}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the linked list. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p = NULL;
    ReviewNode *q = NULL;

    p = head;

    while (p != NULL)
    {
        if (strcmp(p->review.movie_title, title) == 0)
        {
            if (strcmp(p->review.movie_studio, studio) == 0)
            {
                if (p->review.year == year)
                {
                    if (p == head)
                    {
                        q = p->next;
                        free(p);
                        head = q;
                        break;
                    }
                    else
                    {
                        q->next = p->next;
                        free(p);
                        break;
                    }
                    
                }
            }
        }
        q = p;
        p = p->next;
    }

    return head;	// <--- This should change when after you implement your solution
}

void printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the linked list, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"
     * 
     * See the Assignment handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    ReviewNode *p = NULL;

    p = head;

    while (p != NULL)
    {
        printf("%s\n", p->review.movie_title);
        printf("%s\n", p->review.movie_studio);
        printf("%d\n", p->review.year);
        printf("%f\n", p->review.BO_total);
        printf("%d\n", p->review.score);
        printf("*******************\n");
        
        p = p->next;
    }

}

void queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p = NULL;

    p = head;

    while (p != NULL)
    {
        if (strcmp(p->review.movie_studio, studio) == 0)
        {
            printf("%s\n", p->review.movie_title);
            printf("%s\n", p->review.movie_studio);
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("*******************\n");
        }

        p = p->next;
    } 
}

void queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  

    ReviewNode *p = NULL;

    p = head;

    while (p != NULL)
    {
        if (p->review.score >= min_score)
        {
            printf("%s\n", p->review.movie_title);
            printf("%s\n", p->review.movie_studio);
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("*******************\n");
        }

        p = p->next;
    }
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the linked list of movie reviews, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    

    ReviewNode *p = NULL;
    ReviewNode *q = NULL;

    p = head;

    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    return p;	// <--- This should change when after you implement your solution
}

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      

    ReviewNode *p = NULL;
    ReviewNode *largest_item = NULL;
    ReviewNode *new_head = NULL;
    ReviewNode *previous_item = NULL;
    int length = 0;
    int i;

    length = countReviews(head);

    p = head;

    for (i = 0; i < length; i++)
    {
        while (p != NULL)
        {
            if (largest_item == NULL)
            {
                largest_item = p;
            }
            else
            {
                if (strcmp(p->review.movie_title, largest_item->review.movie_title) > 0)
                {
                    largest_item = p;
                }
            }

            p = p->next;
        }

        
        if (largest_item == head)
        {
            head = head->next;
            largest_item->next = new_head;
            new_head = largest_item;
        }
        else if (largest_item != NULL)
        {
            previous_item = head;

            while (previous_item->next != largest_item)
            {
                previous_item = previous_item->next;
            }

            previous_item->next = largest_item->next;
            largest_item->next = new_head;
            new_head = largest_item;
        }
                
        largest_item = NULL;
        p = head;
    }

    return new_head;	// <--- This should change when after you implement your solution
}