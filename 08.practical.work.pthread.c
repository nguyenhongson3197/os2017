+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#define BUFFER_SIZE 10
+
+
+typedef struct
+{
+	  char type; //fried chicken : 0, french fries : 1
+	  int amount; //piece, weight
+	  char unit; //piece : 0, gram : 1
+}item
+
+item bufer[BUFFER_SIZE];
+int first = 0;
+int last = 0;
+
+void produce(item *i){
+       while ((first + 1) % BUFFER_SIZE == last){
+             //no free buffer item      
+       }
+       memcpy(&buffer[first], i, sizeof(item));
+       first=(first+1) % BUFFER_SIZE;
+}
+
+item *consume()	
+{
+	item *i = (item *)malloc(sizeof(item));
+	while(first == last)
+	{	
+	// nothing
+	}
+	memcpy(i, &buffer[last], sizeof(item));
+	last = (last+1) % BUFFER_SIZE;
+	return i;
+}
+
+int main() {
+     item item_x;
+     item_x.type = '1';
+     item_x.amount = 0;
+     item_x.unit = '1';
+
+     printf("Producing item x: type=%c amount=%d unit=%c\n",item_x.type,item_x.amount,item_x.unit);
+     produce(&item_x);
+     log_val();
+
+     item item_y;
+     item_y.type = '0';
+     item_y.amount = 1;
+     item_y.unit = '0';
+
+     printf("Producing item y: type=%c amount=%d unit=%c\n",item_y.type,item_y.amount,item_y.unit);
+     produce(&item_y);
+     log_val();
+     
+     printf("\nAfter consumed once:\n");
+     consume();
+     log_val();
}
+void *consume_thread(void *param) {
+     printf("after consumed 1:");
+     consume();
+     log_val();
+
+     printf("after consumed 2:");
+     consume();
+     log_val();
+}
+int main() {
+     pthread_t tid1, tid2;
+	
+  pthread_create(
+		&tid1,
+		NULL,
+		produce,
+		NULL);
+  pthread_join(tid1, NULL);
+
+	pthread_create(
+		&tid2,
+		NULL,
+		consume,
+		NULL);
+  pthread_join(tid2, NULL);
+}
+
+}
