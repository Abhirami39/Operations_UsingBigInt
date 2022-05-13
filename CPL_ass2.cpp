#include<stdio.h>
#include<string.h>

void add_nos(char n1[], char n2[]){
	int carry = 0, ans_int=0, j= strlen(n2)-1, i= strlen(n1)-1, ans_len=0, ans_len_copy = 0;
	if(j>i){
		ans_len = j+1;
	}
	else{
		ans_len = i+1;
	}
	
	char ans[ans_len];
	
	for(int i=0; i<ans_len; i++){
		ans[i] = '0';
	}
	
	ans_len_copy = ans_len;
	while(i>=0 && j>=0){
		ans_int = (n1[i]-48) + (n2[j]-48) + carry;
		if(ans_int >= 10 ){
			carry = ans_int/10;
			ans_int = ans_int%10;
			ans[ans_len] = ans_int + 48;
		}
		else{
			carry = 0;
			ans[ans_len] = ans_int + 48;
		}
		i--; j--; ans_len--;
	}
	
	while(i>=0){
		ans_int = (n1[i]-48) + carry;
		if(ans_int >= 10){
			carry = ans_int/10;
			ans_int = ans_int%10;
			ans[ans_len] = ans_int + 48;
		}
		else{
			carry = 0;
			ans[ans_len] = ans_int + 48;
		}
		i--; ans_len--;
	}
	
	while(j>=0){
		ans_int = (n2[j]-48) + carry;
		if(ans_int >= 10){
			carry = ans_int/10;
			ans_int = ans_int%10;
			ans[ans_len] = ans_int + 48;
		}
		else{
			carry = 0;
			ans[ans_len] = ans_int + 48;
		}
		j--; ans_len--;
	}
	if(carry == 1){
		ans[0] += 1;
	}
	
	for(int i=0; i<ans_len_copy + 1; i++){
		printf("%c ", ans[i]);
	}
	printf("\n \n \n");
}

int find_bigger_number(char n1[], char n2[]){
	int n1_len = strlen(n1), n2_len = strlen(n2);
	if(n1_len > n2_len){
		return 1;
	}
	else if(n2_len > n1_len){
		return 2;
	}
	else{
		while(i<n1_len && j<n2_len){
			if(n1[i] > n2[j]){
				return 1;
			}
			else if(n1[i] < n2[j]){
				return 2;
			}
			else{
				i++; j++;
			}
		}
	}
	return 0; // they're equal
}

void subtact_arrays_op_pos(char n1[], char n2[]){
	char ans[32];
	int int_ans=0, j= strlen(n2)-1, i= strlen(n1)-1, ans_len=0;
	
	if(j>i){
		ans_len = j;
	}
	else{
		ans_len = i;
	}
	
	for(int i=0; i<ans_len; i++){
		ans[i] = '0';
	}
	
	int ans_len_copy = ans_len + 1;
	
	int big_no = find_bigger_number(n1, n2);
	
	while(i >= 0 && j >= 0){
		if(big_no == 1 || big_no == 0){
			if(n1[i] >= n2[j]){
				int_ans = (n1[i] - 48) - (n2[j] - 48);
				ans[ans_len] = int_ans + 48;
			}
			else{
				n1[i-1]--;
				n1[i] += 10;
				ans[ans_len] = (n1[i] - 48) - (n2[j] - 48) + 48;
			}
		}
		else if(big_no == 2){
			if(n2[j] >= n1[i]){
				int_ans = (n2[j] - 48) - (n1[i] - 48);
				ans[ans_len] = int_ans + 48;
			}
			else{
				n2[j-1]--;
				n2[j] += 10;
				ans[ans_len] = (n2[j] - 48) - (n1[i] - 48) + 48;
			}
		}
		i--; j--; ans_len--;
	}
	while(i >= 0){
		int_ans = (n1[i] - 48);
		ans[ans_len] = int_ans + 48;
		
		i--; ans_len--;
	}
	while(j >= 0){
		int_ans = (n2[j] - 48);
		ans[ans_len] = int_ans + 48;
			
		j--; ans_len--;
	}
	
	printf("printing result of subtracting the arrays  \n");
	for(int i=0; i<ans_len_copy; i++){
		printf("%c ", ans[i]);
	}
	
	printf("\n \n \n");
}

void subtact_arrays_op_signed(char n1[], char n2[]){
	int int_ans=0, j= strlen(n2)-1, i= strlen(n1)-1, ans_len=0;
	
	if(j>i){
		ans_len = j+1;
	}
	else{
		ans_len = i+1;
	}
	
	int ans_len_copy = ans_len + 1;
	
	char ans[ans_len_copy+1];
	
	for(int i=0; i<ans_len+1; i++){
		ans[i] = '0';
	}
	
	
	int big_no = find_bigger_number(n1, n2);
	
	while(i >= 0 && j >= 0){
		if(big_no == 1 || big_no == 0){
			if(n1[i] >= n2[j]){
				int_ans = (n1[i] - 48) - (n2[j] - 48);
				ans[ans_len] = int_ans + 48;
			}
			else{
				n1[i-1]--;
				n1[i] += 10;
				ans[ans_len] = (n1[i] - 48) - (n2[j] - 48) + 48;
			}
		}
		else if(big_no == 2){
			if(n2[j] >= n1[i]){
				int_ans = (n2[j] - 48) - (n1[i] - 48);
				ans[ans_len] = int_ans + 48;
			}
			else{
				n2[j-1]--;
				n2[j] += 10;
				ans[ans_len] = (n2[j] - 48) - (n1[i] - 48) + 48;
			}
		}
		i--; j--; ans_len--;
	}
	while(i >= 0){
		int_ans = (n1[i] - 48);
		ans[ans_len] = int_ans + 48;
		
		i--; ans_len--;
	}
	while(j >= 0){
		int_ans = (n2[j] - 48);
		ans[ans_len] = int_ans + 48;
			
		j--; ans_len--;
	}
	
	if(big_no == 2){
		ans[0] = '-';
	}
	else{
		ans[0] = '+';
	}
	
	printf("printing result of subtracting the arrays  \n");
	for(int i=0; i<ans_len_copy; i++){
		printf("%c ", ans[i]);
	}
	
	printf("\n \n \n");
}

void multiply_nos(char n1[], char n2[]){
	int n1_len = strlen(n1), n2_len = strlen(n2), ans_len = n1_len + n2_len, ans_int = 0, carry = 0;
	char ans[ans_len];
	
	for(int i=0; i<ans_len; i++){
		ans[i] = '0';
	}
	
	for(int i=n1_len-1 ;i>=0 ;i--){
		for(int j=n2_len-1; j>=0; j--){
			ans_int = ((n1[i]-48) * (n2[j]-48)) + (ans[i+j+1]-48);
			if(ans_int >= 10){
				carry = ans_int/10;
				ans[i+j+1] = ans_int%10 + 48;
				ans[i+j] += carry;
			}
			else{
				carry = 0;
				ans[i+j+1] = ans_int + 48;
			}
		}
	}
	printf("printing result of multiplying the arrays \n");
	for(int i=0; i<ans_len; i++){
		printf("%c ", ans[i]);
	}
	
	printf("\n \n \n");
}

main(){
	char str1[32], str2[32], n;
	int count_str1=0, count_str2 =0;
	for(int i=0; i<32; i++){
		str1[i] = '0';
	}
	for(int i=0; i<32; i++){
		str2[i] = '0';
	}
	
	printf("\n Enter first no \n");
	scanf("%s", str1);
	
	fflush(stdin);
	printf("\n Enter second no \n");
	scanf("%s", str2);
	
	add_nos(str1, str2);
	multiply_nos(str1, str2);
	subtact_arrays_op_pos(str1, str2);
	subtact_arrays_op_signed(str1, str2);
}
