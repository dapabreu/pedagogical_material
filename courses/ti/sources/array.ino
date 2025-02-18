int min, max;
float mean;
int nums[] = {180,20,45,55,65,70,80,85,90,95,100,105,110,115,120,130,135,140,150,10};

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  mean = 0;
  Serial.println("Calling arrayProcessing");
  arrayProcessing();
  Serial.print("The minimun element in the arrays is: ");
  Serial.println(min);
  Serial.print("The maximum element in the array is: ");
  Serial.println(max);
  Serial.print("The mean of element of the array is: ");
  Serial.println(mean);
  delay(2000);
}

void arrayProcessing(){
  min = max = nums[0];
  for(int i = 0; i < sizeof(nums)/sizeof(int); i++){
    if (nums[i] < min)
      min = nums[i];
    if (nums[i] > max)
      max = nums[i];
    mean = mean + nums[i];
  }
  mean = mean / (sizeof(nums)/sizeof(int));
}
