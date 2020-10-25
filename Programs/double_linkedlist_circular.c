#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next,*prev;

}*head,*tail,*current;

int i,count = 0;
void insert_at_begin(int data){
	current = (struct node*)malloc(sizeof(struct node));
	current->data = data;
	current->next = current->prev= current;
	
	if(head==NULL){
		head=tail=current;
		head->next = head;
		head->prev = head;
		tail->next = tail;
		tail->prev = tail;
	}else{
		current->next = head;
		head->prev = current;
		head = current;
		head->prev = tail;
		tail->next = head;		
	}
	printf("Done!!\n");
	count++;
}
void insert_at_end(int data){
	current = (struct node*)malloc(sizeof(struct node));
	current->data = data;
	current->next = current->prev = current;
	if(head==NULL){
		head=tail=current;
		head->next = head;
		head->prev = head;
		tail->next = tail;
		tail->prev = tail;
	}else{
		tail->next = current;
		current->prev = tail;
		tail = current;
		tail->next = head;
		head->prev = tail;
	}
	printf("Done!!\n");
	count++;
}
void print_depan(){
	current = head;
	if(current!=NULL){
		printf("--------------------------------\n");
		printf("Show data from the front:\n");
		do{
			printf("%d ",current->data);
			current=current->next;
		}while(current!=head);
		printf("\n--------------------------------\n");
	printf("\n");
	}else{
		printf("No Data!\n");
	}
}
void print_search(int data){
	int temp,temp2;
	int hitung;
	temp = temp2 = 0;
	current = head;
	if(current!=NULL){
		printf("--------------------------------\n");
		do{
			if(current->data == data){
				temp2++;
				hitung = temp2;
				printf("data ke-%d dari depan : %d\n",hitung,current->data);
				temp++;
				current=current->next;
			}else{
				current=current->next;
				temp2++;
			}
		}while(current!=head);
		if(temp != 0){
			printf("\nGot %d data!", temp);
		}else{
			printf("\nThere is no %d in range", data);
		}
		printf("\n--------------------------------\n");
	printf("\n");
	}else{
		printf("No Data!\n");
	}
}
void print_belakang(){
	current = tail;
	if(current!=NULL){
		printf("--------------------------------\n");
		printf("Showing data from behind :\n");
		do{
			printf("%d ",current->data);
			current=current->prev;
		}while(current!=tail);
		printf("\n--------------------------------\n");
		printf("\n");
	}else{
		printf("Tidak ada Data!\n");
	}
}
void delete_from_begin(){
	if(head==NULL){
		printf("No data!!\n");
	}else if(head==tail){
		current=head;
		head=tail=NULL;
		free(current);
		printf("data deleted!!\n");
		count--;
	}else{
		current=head;
		head=head->next;
		tail->next = head;
		head->prev = tail;
		free(current);
		printf("data deleted!!\n");
		count--;
	}
}
void delete_from_end(){
	if(head==NULL){
		printf("No data!!\n");
	}else if(head==tail){
		current=tail;
		head=tail=NULL;
		free(current);
		printf("data deleted!!\n");
		count--;
	}else{
		current=tail;
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		free(current);
		printf("data deleted!!\n");
		count--;
	}
}
void delete_from_middle(int data,int posisi){
	if(head==NULL){
		printf("No data!!\n");
	}else{
		current=head;
		for(i=1;i<posisi;i++){
			current=current->next;	
		}
			if(current==head){
				delete_from_begin();
			}else if(current==tail){
				delete_from_end();
			}else{
				current->prev->next=current->next;
				current->next->prev=current->prev;
				free(current);
				count--;
				printf("data deleted!!\n");
			}
	}
}
void delete_all(){
	while(head!=NULL){
		delete_from_begin();
	}
	printf("All data have been deleted!\n");
}
int main(){
	int data,posisi,pilih=0;
	while(pilih!=10){
		printf("1. Insert from begin\n");
		printf("2. Insert from end\n");
		printf("3. Show data from begin\n");
		printf("4. Show data from end\n");
		printf("5. Search data\n");
		printf("6. Delete data from begin\n");
		printf("7. Delete data from end\n");
		printf("8. Delete data from position\n");
		printf("9. Delete all data\n");
		printf("10. exit\n");
		printf("Masukan Pilihan : ");
		scanf("%d", &pilih);
		switch(pilih){
			case 1:
				printf("Insert a Number : ");
				scanf("%d", &data);
				insert_at_begin(data);
				break;
			case 2:
				printf("Insert a Number : ");
				scanf("%d", &data);
				insert_at_end(data);
				break;
			case 3:
				print_depan();
				break;
			case 4:
				print_belakang();
				break;
			case 5:
				if(count == 0){
					printf("There is No data !!\n");
					break;
				}else{
					printf("Insert a Number for searching : ");
					scanf("%d", &data);
					print_search(data);
					break;
				}
			case 6:
				delete_from_begin();
				break;
			case 7:
				delete_from_end();
				break;
			case 8:
				if(count == 0){
					printf("No Data!!\n");
					break;
				}else{
					printf("There is/are %d data\n", count);
					printf("What Position of data you want to delete? ");
					scanf("%d", &posisi);
					if(posisi <= 0 || posisi > count){
						printf("data at position-%d not found!!\n", posisi);
					}else{
					delete_from_middle(data,posisi);
					}
				break;
				}
			case 9:
				delete_all();
				break;
			case 10:
				printf("Thanks!!");
				break;
			default:
				printf("Wrong  Input!\n");
				break;
		}
	}
	return 0;
}
