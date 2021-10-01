import 'package:christmas_tree/screen/my_colors.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/painting.dart';

class Christmas extends StatefulWidget {
  @override
  _ChristmasState createState() => _ChristmasState();
}

class _ChristmasState extends State<Christmas> {
  var _offset = Offset.zero;
  @override
  Widget build(BuildContext context) {
    return Material(
      color: Colors.grey[300],
      child: Stack(
        children: [
          Transform(
            alignment: FractionalOffset.center,
            transform: Matrix4.identity()
              ..setEntry(3, 2, 0.001)
              ..rotateX(0.01 * _offset.dy)
              ..rotateY(-0.01 * _offset.dx),
            child: GestureDetector(
              onPanUpdate: (details) {
                setState(() {
                  _offset += details.delta;
                });
              },
              onDoubleTap: () {
                setState(() {
                  _offset = Offset.zero;
                });
              },
              child: Stack(
                alignment: Alignment.center,
                children: [
                  Positioned(
                    top: 500,
                    child: Container(
                      height: 180,
                      width: 150,
                      decoration: BoxDecoration(
                        borderRadius: BorderRadius.only(
                            bottomLeft: Radius.circular(40),
                            bottomRight: Radius.circular(40)),
                        gradient: LinearGradient(
                          begin: Alignment.topCenter,
                          end: Alignment.bottomCenter,
                          colors: [MyColors.yellow1, MyColors.yellow2],
                        ),
                      ),
                    ),
                  ),
                  Positioned(
                    top: 250,
                    child: CustomPaint(
                      foregroundPainter: BannerPainter(
                        message: "Merry Christmas",
                        location: BannerLocation.bottomEnd,
                        textDirection: TextDirection.ltr,
                        color: Colors.red,
                        layoutDirection: TextDirection.ltr,
                        textStyle: TextStyle(fontSize: 8),
                      ),
                      painter: MyTriangle(),
                      size: Size.square(300),
                    ),
                  ),
                  Positioned(
                    top: 200,
                    child: CustomPaint(
                      painter: MyTriangle(),
                      size: Size.square(250),
                    ),
                  ),
                  Positioned(
                    top: 150,
                    child: CustomPaint(
                      painter: MyTriangle(),
                      size: Size.square(170),
                    ),
                  ),
                  Positioned(
                    top: 125,
                    child: Icon(
                      CupertinoIcons.star_fill,
                      color: Colors.white,
                      size: 70,
                    ),
                  ),
                  RedCircle(top: 500),
                  RedCircle(top: 420),
                  RedCircle(top: 420, right: 100),
                  RedCircle(top: 400, right: 270),
                  RedCircle(top: 290),
                  RedCircle(top: 200),
                  RedCircle(
                    top: 510,
                    color: Colors.orange,
                    right: 290,
                  ),
                  RedCircle(
                    top: 350,
                    color: Colors.orange,
                    right: 135,
                  ),
                ],
              ),
            ),
          ),
          Positioned(
            bottom: 10,
            right: 10,
            child: FloatingActionButton(
              onPressed: () {
                setState(() {
                  _offset = Offset.zero;
                });
              },
              child: Icon(Icons.replay_outlined),
              elevation: 0.0,
              backgroundColor: MyColors.green2,
            ),
          )
        ],
      ),
    );
  }
}

class RedCircle extends StatelessWidget {
  final Color color;
  final double top;
  final double right;
  RedCircle({this.top, this.right, this.color = Colors.red});
  @override
  Widget build(BuildContext context) {
    return Positioned(
      top: top,
      right: right,
      child: CircleAvatar(
        radius: 10,
        backgroundColor: color,
      ),
    );
  }
}

class MyTriangle extends CustomPainter {
  @override
  void paint(Canvas canvas, Size size) {
    var path = Path();
    path.moveTo(size.width / 2, 0);
    path.lineTo(0, size.height);
    path.lineTo(size.width, size.height);
    path.close();

    var paint = Paint()
      ..style = PaintingStyle.fill
      ..shader = LinearGradient(
        begin: Alignment.topCenter,
        end: Alignment.bottomCenter,
        colors: [MyColors.green1, MyColors.green2],
      ).createShader(Rect.fromLTRB(0, 0, size.height, size.width));
    canvas.drawPath(path, paint);
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) {
    return true;
  }
}
