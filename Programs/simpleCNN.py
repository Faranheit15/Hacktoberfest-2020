from IPython import get_ipython
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
get_ipython().run_line_magic('matplotlib', 'inline')

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt



transform= transforms.ToTensor()



train_data=datasets.MNIST(root=r"C:\Users\hp\Downloads\Machine Learning Stuff\Pytorch\PYTORCH-NOTEBOOKS (1)\PYTORCH_NOTEBOOKS\Data",train=True, transform=transform,download=False)
test_data=datasets.MNIST(root=r"C:\Users\hp\Downloads\Machine Learning Stuff\Pytorch\PYTORCH-NOTEBOOKS (1)\PYTORCH_NOTEBOOKS\Data",train=False, transform=transform,download=False)



train_data



test_data



trainloader=DataLoader(train_data,batch_size=10,shuffle=True)
testloader=DataLoader(test_data,batch_size=10,shuffle=True)



for (x_train,y_train) in train_data:
  break;



(x_train).size()



class CNN(nn.Module):
  def __init__(self):
    super().__init__()
    self.conv1=nn.Conv2d(1,6,3,1)
    self.conv2=nn.Conv2d(6,16,3,1)
    self.fc1= nn.Linear(16*5*5,120)
    self.fc2=nn.Linear(120,84)
    self.fc3=nn.Linear(84,10)

  def forward(self,X):
    X= F.relu(self.conv1(X))
    X= F.max_pool2d(X,2,2)
    X=F.relu(self.conv2(X))
    X= F.max_pool2d(X,2,2)
    X=X.view(-1,16*5*5)
    X= self.fc1(X)
    X=self.fc2(X)
    X=self.fc3(X)

    return F.log_softmax(X,dim=1)



model=CNN()
model



criterion= nn.CrossEntropyLoss()
optimizer= torch.optim.Adam(model.parameters(),lr=0.001)



train_losses=[]
test_losses=[]
train_crt=[]
test_crt=[]

epochs=5

for i in range(epochs):

  train_crtc=0
  test_crtc=0

  for b,(X_train,y_train) in enumerate(trainloader):
    b+=1
    y_pred=model(X_train)
    loss= criterion(y_pred,y_train)

    predict= torch.max(y_pred.data,1)[1]
    b_crct= (predict==y_train).sum()
    train_crtc+=b_crct


    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    if(b%600==0):
      print(f" Epoch: {i} Batch:{b} Loss:{loss.item()}")
    
  train_losses.append(loss)
  train_crt.append(train_crtc)

  with torch.no_grad():

    for b,(X_test,y_test) in enumerate(testloader):

      y_pred=model(X_test)
      predict=torch.max(y_pred.data,1)[1]
      b_crt=(predict==y_test).sum()
      test_crtc+=b_crt

  loss=criterion(y_pred,y_test)
  test_losses.append(loss)
  test_crt.append(test_crtc)



plt.plot(train_losses,label="Train_Loss")
plt.plot(test_losses,label="Test Loss")
plt.legend()
