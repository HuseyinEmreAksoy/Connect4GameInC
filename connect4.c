#include <stdio.h>
#define row 6
#define col 7
#define four 4

char scores [row][col];
char upDown[] = "X 0 1 2 3 4 5 6 X";

int place = 0;
char disc = 'R';
int c = 0;
int player = 0;
int draw = 0;

void put();
void board();
int check(char disc);

int main(){
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			scores[i][j] = ' ';
	board();
			
	while(1){
		draw = 0;
        	player = 1; 
        	put();
        	printf("\n");
        	board();
        	if (check('R')){
            		printf("\nPlayer 1 wins!\n");
            		break;  
        	}		
        	player = 2;
        	put();
        	printf("\n");
        	board();
        	
        	if (check('Y')){
            		printf("\nPlayer 2 wins!\n");
            		break;  
        	}
        	for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				if(scores[i][j] != ' ')
					draw++;
		if(draw == 42){
			printf("\nDraw!\n");
			break;
		}
	}
    	
	return 0;
}

void board(){
	printf("%s\n", upDown);
    
    for (int i = 0; i < row; i++)
    {
    	printf("%d",i);
        for (int j = 0; j < col; j++)
        {
        	if(scores[i][j] == 'R' || scores[i][j] == 'Y')
            		printf(" %c", scores[i][j]);
            	else
            		printf(" -");
        }
        printf(" %d\n",i);

    }
    	printf("%s\n", upDown);
}
void put(){
	
	
	while(1){
		if(player == 1){
			printf("Player 1's Turn (%c):\n", disc);
			printf("Enter a move: ");  
			scanf("%d", &c);
		}
		else if(player == 2){
			printf("Player 2's Turn (%c):\n", disc);
			printf("Enter a move: ");  
			scanf("%d", &c);
		}
		switch(c){
			case 0:
			place = 0;
			break;
		    case 1:
		        place = 1;
		        break;
		    case 2:
		        place = 2;
		        break;
		    case 3:
		        place = 3;
		        break;
		    case 4:
		        place = 4;
		        break;
		    case 5:
		        place = 5;
		        break;
		    case 6:
		        place = 6;
		        break;
		    default:
		        place = -1;
		        printf("\nEntered move is not valid!\n\n");
		        board();
		    	break;	    
		}
		if ((place > -1 && place < 7) && (scores[0][place] == ' '))
        	{
            		for (int i = row - 1; -1 < i; i--)
        			if (scores[i][place] == ' ')
        			{
            				scores[i][place] = disc;
            				break;
        			}   	   
            		disc = (disc == 'R') ? 'Y' : 'R';
            		break;
        	}else if ((place > -1 && place < 7) && (scores[0][place] != ' ')){
			printf("\nThe column is full, try again!\n\n");
			board();
        	}
	}
}
int check(char disc){
     
    int i, j, k;
    int count;
    int ways = 4;
    
    for (i = 0; i < row; ++i)
        for (j = 0; j < ways; ++j){
            count = 0;
            for (k = 0; k < four; ++k)
                if (scores[i][j + k] == disc) 
                	count++;
            
            if (count == four) 
            	return 1;
        }
    
    ways = 3;
    
    for (j = 0; j < col; ++j)
        for (i = 0; i < ways; ++i){
            count = 0;
            for (k = 0; k < four; ++k)
                if (scores[i + k][j] == disc) 
                	count++;
            
            if (count == four) 
            	return 1;
        }
    
    int lDiag, rDiag;
    for (i = 1; i < row-1; i++)
    {
        for (j = 1; j < col-1; j++){
            count = 0;
            for (lDiag = i, rDiag = j; (lDiag >= 0) || (rDiag >= 0); lDiag--, rDiag--)
                if (scores[lDiag][rDiag] == disc){
                    count++;
                    if (count == four) 
                    	return 1;    
                }
                else
                    break;

            for (lDiag = i+1, rDiag = j+1; (lDiag <= row-1) || (rDiag <= col-1); lDiag++, rDiag++)
                if (scores[lDiag][rDiag] == disc){
                    count++;
                    if (count == four) return 1;
                }
                else
                    break;
            count = 0;
            for (lDiag = i, rDiag = j; (lDiag <= row-1) || (rDiag >= 0); lDiag++, rDiag--)
                if (scores[lDiag][rDiag] == disc){
                    count++;
                    if (count == four) 
                    	return 1;    
                }
                else
                    break;

            for (lDiag = i-1, rDiag = j+1; (lDiag >= 0) || (rDiag <= col-1); lDiag--, j++)
                if (scores[lDiag][rDiag] == disc){
                    count++;
                    if (count == four) return 1;
                }
                else
                    break;
        }
    }

    return 0;       
}

