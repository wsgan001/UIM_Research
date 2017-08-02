// This program calculates the total weighted utility from the itemset generated by SyntheticData.c.
// Going forward, this program should be able to find groupings from categories that pass the first test, and make pairings of two and up.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE *myFile;
	myFile = fopen("1000Entries.txt", "r");

	int i;
	int overallRating[1000];
	int quality[1000];
	int price[1000];
	int time[1000];
	int userInterface[1000];
	int design[1000];
	int color[1000];

    int totalWeightedUtility[1000];



    int qualityWU = 0;
	int priceWU = 0;
	int timeWU = 0;
	int userInterfaceWU = 0;
	int designWU = 0;
	int colorWU = 0;

	if (myFile == NULL)
    {
        printf("Error Reading File\n");
        exit (0);
    }
    for (i = 0; i < 1000; i++)
    {
        fscanf(myFile, " %d %d %d %d %d %d %d", &overallRating[i], &quality[i], &price[i], &time[i], &userInterface[i], &design[i], &color[i]);

    }

    fclose(myFile);

    for(i=0; i<1000; i++){
    	totalWeightedUtility[i] = overallRating[i] * (quality[i] + price[i] 
                                        + time[i] + userInterface[i] + design[i] + color[i]);

    	if(quality[i] > 0){
    		qualityWU += totalWeightedUtility[i];
    	}
    	if(price[i] > 0){
    		priceWU += totalWeightedUtility[i];
    	}
    	if(time[i] > 0){
    		timeWU += totalWeightedUtility[i];
    	}
    	if(userInterface[i] > 0){
    		userInterfaceWU += totalWeightedUtility[i];
    	}
    	if(design[i] > 0){
    		designWU += totalWeightedUtility[i];
    	}
    	if(color[i] > 0){
    		colorWU += totalWeightedUtility[i];
    	}
    }

    printf("\nSingles\n");

    printf("Quality WU: %d\n", qualityWU);
    printf("Price WU: %d\n", priceWU);
    printf("Time WU: %d\n", timeWU);
    printf("UserInterface WU: %d\n", userInterfaceWU);
    printf("Design WU: %d\n", designWU);
    printf("Color WU: %d\n", colorWU);

    // After testing one value, threshold could be set to 11,000. If so, quality, price, and time pass.
    // A threshold of 10,000 might be more interesting. If so, only design doesn't pass.

    int qpWU = 0;
	int qtWU = 0;
	int quWU = 0;
	int qcWU = 0;

	int ptWU = 0;
	int puWU = 0;
	int pcWU = 0;

	int tuWU = 0;
	int tcWU = 0;

	int ucWU = 0;

    for(i=0; i<1000; i++){
    	if(quality[i] > 0 && price[i] > 0){
    		qpWU += totalWeightedUtility[i];
    	}
    	if(quality[i] > 0 && time[i] > 0){
    		qtWU += totalWeightedUtility[i];
    	}
    	if(quality[i] > 0 && userInterface[i] > 0){
    		quWU += totalWeightedUtility[i];
    	}
    	if(quality[i] > 0 && color[i] > 0){
    		qcWU += totalWeightedUtility[i];
    	}

    	if(price[i] > 0 && time[i] > 0){
    		ptWU += totalWeightedUtility[i];
    	}
    	if(price[i] > 0 && userInterface[i] > 0){
    		puWU += totalWeightedUtility[i];
    	}
    	if(price[i] > 0 && color[i] > 0){
    		pcWU += totalWeightedUtility[i];
    	}

    	if(time[i] > 0 && userInterface[i] > 0){
    		tuWU += totalWeightedUtility[i];
    	}
    	if(time[i] > 0 && color[i] > 0){
    		tcWU += totalWeightedUtility[i];
    	}

    	if(userInterface[i] > 0 && color[i] > 0){
    		ucWU += totalWeightedUtility[i];
    	}


    }

    printf("\nDoubles\n");

    printf("Quality and Price WU: %d\n", qpWU);
    printf("Quality and Time WU: %d\n", qtWU);
    printf("Quality and UserInterface WU: %d\n", quWU);
    printf("Quality and Color WU: %d\n", qcWU);

    printf("Price and Time WU: %d\n", ptWU);
    printf("Price and UserInterface WU: %d\n", puWU);
    printf("Price and Color WU: %d\n", pcWU);

    printf("Time and UserInterface WU: %d\n", tuWU);
    printf("Time and Color WU: %d\n", tcWU);

    printf("UserInterface and Color WU: %d\n", ucWU);

    // Only Quality, Price, and Time pass

    int qptWU = 0;

    for(i = 0; i<1000; i++){
    	if(quality[i] > 0 && price[i] > 0 && time[i] > 0){
    		qptWU += totalWeightedUtility[i];
    	}
    }

    printf("\nTriples\n");

    printf("Quality, Price, and Time WU: %d\n", qptWU);
    printf("\n");

    // This trio also passes.
    // Still having troubles with making this an iterative process, ideas:
    // Using an array, that way you don't have to set up variables for each Weighted Utility
    // In Python, a list might be able to do what I'm looking for

}