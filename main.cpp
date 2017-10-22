#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

char* strupr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = toupper((unsigned char) *tmp);
    }

    return s;
}

int main(int argc, char **argv)
{
	//printf("hello world\n");
    
    char c,h,ch,ch1,ch2,word[25],word2[25];
    int l,i,ng,n,k,x;
    
    do
    {
        do
        {
            c = '\0';
            cout<<"\n\t\t******** HANGMAN GAME IN C++ ********\n\n";
            cout<<"(E) Enter a word\n\n";
            cout<<"(C) Computer chooses word\n\n";
            cout<<"(A) Add new word to list\n\n";
            cout<<"(Q) Quit\n\n\n";
            cout<<"Enter your choice (E - C - Q): ";
            fflush(stdin);
            cin>>ch2;
        }while(ch2!='e'&&ch2!='E'&&ch2!='c'&&ch2!='C'&&ch2!='a'&&ch2!='A'&&ch2!='q'&&ch2!='Q');
        
        if(ch2 == 'q' || ch2 == 'Q')
        {
            exit(0);
        }
        else if(ch2 == 'c' || ch2 == 'C')
        {
            ifstream fin("hangword.txt");
            
            if(!fin)
            {
                cout<<"File missing";
                cin.ignore().get();
                return 0;
            }
            
            for(i=0;!fin.eof();i++)
            {
                fin.getline(word,25);
            }
            
            fin.close();
            
            do
            {
                x = rand();
            }while(x>i || x<0);
            
            ifstream finn("hangword.txt");
            
            for(i=0;!finn.eof();i++)
            {
                finn>>c;
                finn.getline(word,25);
                if(x==i)
                {
                    break;
                }
            }
            
            finn.close();
        }
        else if(ch2 == 'a'&& ch2 == 'A')
        {
            ofstream fout("hangword.txt",ios::app);
            
            if(!fout)
            {
                system("clear");
                cout<<"File missing";
                cin.ignore().get();
                return 0;
            }
            
            //cin.ignore().get();
            
            cout<<"Choose the topic of your word\n\n";
            cout<<"(M) Movie\n\n";
            cout<<"(A) Animal\n\n";
            cout<<"(P) Sport\n\n";
            cout<<"(S) Song\n\n";
            
            cout<<"Enter your choice (A-P-S-M) : ";
            cin>>h;
            
            system("clear");
            
            cout<<"The word should not exceed 25 letters\n\n";
            cout<<"Enter the word : ";
            cin.getline(word,25);
            
            fout<<h<<word<<endl;
            
            fout.close();
        }
        else if(ch2 =='E' || ch2 == 'e')
        {
            system("clear");
            cout<<"\t\t\tType the word : ";
            cin.getline(word,25);
        }
        
        if(ch2 == 'E' || ch2 == 'e' || ch2 == 'C' || ch2 == 'c')
        {
            l = strlen(word);
            char choosen[25] = "\0";
            n=k=0;
            
            for(i=0;i<=24;i++)
            {
                if(word[i] == '\0')
                {
                    word2[i] = '\0';
                    break;
                }
                if(word[i] ==' ')
                {
                    word2[i] = ' ';
                    n++;
                }
                if(word[i] != ' ')
                {
                    word2[i] = '-';
                }
            }
            
            ng = l-n+2;
            
            do
            {
                there:
                
                //type_of_word(c);
                
                if(k != 0)
                {
                    cout<<"\n\n\t\t\tChoosen letters : "<<choosen<<"\n";
                }
                
                cout<<"\n\n\n\t\t\t"<<word2;
                cout<<"\n\nYou have "<<ng<<" guesses left, choose a letter : ";
                cin>>ch;
                
                for(i=0;i<25;i++)
                {
                    if(choosen[i] == ch)
                    {
                        system("clear");
                        cout<<"\a\t\t!!You have choosen "<<ch<<" already!!\n";
                        goto there;
                    }
                }
                
                ng--;
                
                choosen[k] = ch;
                choosen[k+1] = ',';
                k+=2;
                
                for(i=0;i<25;i++)
                {
                    if(word[i] == ch || word[i] == ch+32 || word[i] == ch-32)
                    {
                        word[i] = ch;
                    }
                }
                
                if(!strcasecmp(word2,word))
                {
                    cout<<"\n\t\t\t"<<strupr(word)<<"\n\n\t\t\t";
                    cout<<"Congratulations :- ()\n";
                    break;
                }
            }while(ng>0 || strcasecmp(word2,word));
            
            if(strcasecmp(word2,word))
            {
                cout<<"Sorry, maybe next time.";
                cout<<"\n\n";
                cout<<"The word was : "<<strupr(word)<<endl;
            }
        }
        
        cout<<"\nWould you like to play again??? (Y - N) : ";
        cin>>ch1;
        
    }while (ch1=='y' || ch1=='Y');
    
    system("clear");
        
	return 0;
}