import java.util.*;
class A implements Runnable{
    public synchronized void run(){
        for(int i=1;i<=5;i++){
            try{
                Thread.sleep(500);
            }
            catch(InterruptedException e){
                System.out.println(e);
            }
            System.out.println(i);
        }
    }
}
class MultiThread {
    public static void main(String args[]) {
        A obj = new A();
        Thread t1 = new Thread(obj) ;
        Thread t2 = new Thread(obj) ;
        t1.start();
        t2.start();
    }
}