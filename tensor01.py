# _*_ coding: utf-8 _*_
from __future__ import print_function
import tensorflow as tf
import numpy as np
from matplotlib import pyplot as plt
import random

##！！还可以这么写？也就是说Weights/biases /Wx_plus_b不是临时变量，又tensorflow管理
def add_layer(inputs, in_size, out_size, activation_function=None):
    # add one more layer and return the output of this layer
    Weights = tf.Variable(tf.random_normal([in_size, out_size]))#第一层是1*10，第二层是10*1
    biases = tf.Variable(tf.zeros([1, out_size]) + 0.1)
    Wx_plus_b = tf.matmul(inputs, Weights) + biases
    if activation_function is None:
        outputs = Wx_plus_b
    else:
        outputs = activation_function(Wx_plus_b)
    return outputs

# Make up some real data
x_data = np.linspace(-1,1,3000)[:, np.newaxis]#300行一列的二维矩阵。300*1
noise = np.random.normal(0, 0.05, x_data.shape)#300*1
y_data = np.square(x_data) - 0.5 + noise#不是矩阵乘

# define placeholder for inputs to network
xs = tf.placeholder(tf.float32, [None, 1])#可能输入N组数据
ys = tf.placeholder(tf.float32, [None, 1])
# add hidden layer
l1 = add_layer(xs, 1, 10, activation_function=tf.nn.relu)
# add output layer
prediction = add_layer(l1, 10, 1, activation_function=None)

# the error between prediciton and real data
loss = tf.reduce_mean(tf.reduce_sum(tf.square(ys - prediction),
                     reduction_indices=[1]))
train_step = tf.train.GradientDescentOptimizer(0.1).minimize(loss)

# important step
init = tf.initialize_all_variables()
sess = tf.Session()
sess.run(init)

# plot the real data
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
ax.scatter(x_data, y_data)
plt.ion()
plt.show()

def next_batch(xdata,ydata):
    x=int(random.uniform(0, 2901))
    x_data1=[]
    y_data1=[]
    print(len(xdata),len(ydata))
    for t in range(x,x+100):
        x_data1.append(xdata[t])
        y_data1.append(ydata[t])
    return x_data1,y_data1

for i in range(1000):
    # training
    x_data2, y_data2= next_batch(x_data,y_data)
    sess.run(train_step, feed_dict={xs: x_data2, ys: y_data2})
    if i % 50 == 0:
        # to visualize the result and improvement
        try:
            ax.lines.remove(lines[0])
        except Exception:
            pass
        prediction_value = sess.run(prediction, feed_dict={xs: x_data})
        # plot the prediction
        lines = ax.plot(x_data, prediction_value, 'r-', lw=5)
        plt.pause(0.1)
input()
