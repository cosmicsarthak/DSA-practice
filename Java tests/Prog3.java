// Deleting a node at beginning or at end or in b/w.

import java.util.Scanner;
class Link3 {
	int info;
	Link3 next;
}

public class Prog3 {
	static Link3 head=null;
	
	// Creating & Assigning values to the node
	public static void create(Link3 node) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the first node");
		node.info=sc.nextInt();
		node.next=null;
		System.out.println("Enter 0 to exit or 1 to continue");
		int x=sc.nextInt();
		while(x!=0) {
			Link3 temp=new Link3();
			System.out.println("Enter the value for the next node");
			temp.info=sc.nextInt();
			temp.next=null;
			node.next=temp;
			node=temp;
			System.out.println("Enter 0 to exit or 1 to continue");
			x=sc.nextInt();
		}
	}
	
	// deleting a node 
	public static void delete(Link3 node) {
			Link3 prev=new Link3();
			Scanner sc= new Scanner(System.in);
			System.out.println("\nEnter the Node location to delete:");
			int loc=sc.nextInt();
			//delete a node from the beginning :
			if(loc==1) {
				head=node.next;
			}   //delete a node b/w the nodes || at the end :
			else {
				int i=1;
				while(i<loc) {
					prev=node;
					node=node.next;
					i++;	
				}
				prev.next=node.next;
			}
		}
	
	//display the nodes
	public static void display(Link3 node) {
		while(node != null) {
			System.out.print(node.info + "----->");
			node=node.next;
		}
		System.out.println();
	}
	
     //main program
	public static void main(String[] args) {
		Link3 node = new Link3();
		head=node;
		create(head);
		display(head);
        delete(head);
        display(head);
	}
}

