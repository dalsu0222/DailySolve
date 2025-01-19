import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for(int i=0 ; i<tc ; i++) {
            int n = sc.nextInt();
            String max_name = "";
            int max_sul = -1;
            for(int j=0 ; j<n ; j++) {
                String university = sc.next();
                int sul = sc.nextInt();
                if(sul > max_sul) {
                    max_sul = sul;
                    max_name = university;
                }
            }
            System.out.println(max_name);
        }
    }
}