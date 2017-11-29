// base_linkからbase_laserへのtransformをpublish
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv) {
	ros::init(argc, argv, "robot_tf_publisher");
	ros::NodeHandle n;

	ros::Rate r(100);

	tf::TransformBroadcaster broadcaster;

	while(n.ok()) {
		broadcaster.sendTransform(
			tf::StampedTransform(
				tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.2)),
				// argument1:２つのcoordinate frameの間に生じる回転を表す回転行列btQuaternion
				// argument2:２つのcoordinate frameの間に生じる移動を表すbtVector3
				// argument3:transformがpublishされたタイムスタンプを渡す
				// argument4:現在作ろうとしているリンクの親ノードの名前
				// argument5:現在作ろうとしているリンクの子ノードの名前
				ros::Time::now(), "base_link", "base_laser"));
		r.sleep();
	}
}
