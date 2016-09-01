#ifndef __SAMPLE_DATA_GENERATOR_H__
#define __SAMPLE_DATA_GENERATOR_H__

#include "ArcSegment.h"
#include "ArcTriangle.h"
#include "ArcQuad.h"

static void addLogo(
  Vector3D p, float angle, float scale,
  std::vector<ArcSegment>&   arcSegs,
  std::vector<ArcTriangle>&  arcTriangles,
  std::vector<ArcQuad>&      arcQuads
) {

  std::vector<Matrix4x4> matrixSequence;

  matrixSequence.push_back(UnifiedMath::translate(p));
  matrixSequence.push_back(UnifiedMath::rotate(angle, Vector3D(0.0f, 0.0f, 1.0f)));
  matrixSequence.push_back(UnifiedMath::scale(Vector3D(scale)));
  matrixSequence.push_back(UnifiedMath::translate(Vector3D(.0f, 0.5f, 0.0f)));
  matrixSequence.push_back(UnifiedMath::scale(Vector3D(1.0f / 2.0f, 1.0f / 2.0f, 1.0f)));

  Matrix4x4 shapeTransformation = UnifiedMath::matrixSequenceMultiply(matrixSequence);

  ArcTriangle arc[4];
  
  arc[0].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 1.0f, 0.0f));
  arc[0].p2      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.0f, 0.0f, 0.0f));
  arc[0].p3      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.0f, 1.0f, 0.0f));
  arc[0].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.0f, 1.0f, 0.0f));
  arcTriangles.push_back(arc[0]);

  arc[1].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( 0.0f, 1.0f, 0.0f));
  arc[1].p2      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-1.0f, 0.0f, 0.0f));
  arc[1].p3      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-1.0f, 1.0f, 0.0f));
  arc[1].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( 0.0f, 0.0f, 0.0f));
  arcTriangles.push_back(arc[1]);

  arc[2].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-1.0f,  0.0f, 0.0f));
  arc[2].p2      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( 0.0f, -1.0f, 0.0f));
  arc[2].p3      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-1.0f, -1.0f, 0.0f));
  arc[2].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( 0.0f, 0.0f, 0.0f));
  arcTriangles.push_back(arc[2]);

  arc[3].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( 0.0f, -1.0f, 0.0f));
  arc[3].p2      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( 1.0f,  0.0f, 0.0f));
  arc[3].p3      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( 1.0f, -1.0f, 0.0f));
  arc[3].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( 0.0f, 0.0f, 0.0f));
  arcTriangles.push_back(arc[3]);
}

static void addC(
  Vector3D p, float angle, float scale,
  std::vector<ArcSegment>& arcSegments, 
  std::vector<ArcTriangle>& arcTriangles, 
  std::vector<ArcQuad>& arcQuads
) {

  // BBOX = MIN[-2.0f, -2.0f] MAX[1.4f, 2.0f]

  std::vector<Matrix4x4> matrixSequence;

  matrixSequence.push_back(UnifiedMath::translate(p));
  matrixSequence.push_back(UnifiedMath::rotate(angle, Vector3D(0.0f, 0.0f, 1.0f)));
  matrixSequence.push_back(UnifiedMath::scale(Vector3D(scale)));
  matrixSequence.push_back(UnifiedMath::translate(Vector3D(.0f, 0.5f, 0.0f)));
  matrixSequence.push_back(UnifiedMath::scale(Vector3D(1.0f / 3.4f, 1.0f / 4.0f, 1.0f)));
  matrixSequence.push_back(UnifiedMath::translate(Vector3D(+0.3f, 0.0f, 0.0f)));

  Matrix4x4 shapeTransformation = UnifiedMath::matrixSequenceMultiply(matrixSequence);

  ArcSegment arcSegment0, arcSegment1;

  arcSegment0.p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.4f, 1.4f, 0.0f));
  arcSegment0.p2      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.7f, 0.7f, 0.0f));
  arcSegment0.center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.05f, 1.05f, 0.0f));
  arcSegment0.createBuffer();
  arcSegments.push_back(arcSegment0);

  arcSegment1.p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.7f, -0.7f, 0.0f));
  arcSegment1.p2      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.4f, -1.4f, 0.0f));
  arcSegment1.center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.05f, -1.05f, 0.0f));
  arcSegment1.createBuffer();
  arcSegments.push_back(arcSegment1);

  ArcQuad arcQuad0, arcQuad1, arcQuad2, arcQuad3;
  arcQuad0.halfArcQuad[0].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 2.0f, 0));
  arcQuad0.halfArcQuad[0].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.4f, 1.4f, 0));
  arcQuad0.halfArcQuad[0].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 0.0f, 0));

  arcQuad0.halfArcQuad[1].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 1.0f, 0));
  arcQuad0.halfArcQuad[1].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.7f, 0.7f, 0));
  arcQuad0.halfArcQuad[1].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 0.0f, 0));

  arcQuad0.createBuffer();
  arcQuads.push_back(arcQuad0);

  arcQuad1.halfArcQuad[0].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, -2.0f, 0));
  arcQuad1.halfArcQuad[0].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 2.0f, 0));
  arcQuad1.halfArcQuad[0].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 0.0f, 0));

  arcQuad1.halfArcQuad[1].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, -1.0f, 0));
  arcQuad1.halfArcQuad[1].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 1.0f, 0));
  arcQuad1.halfArcQuad[1].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 0.0f, 0));

  arcQuad1.createBuffer();
  arcQuads.push_back(arcQuad1);

  arcQuad2.halfArcQuad[0].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.4f, -1.4f, 0));
  arcQuad2.halfArcQuad[0].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, -2.0f, 0));
  arcQuad2.halfArcQuad[0].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 0.0f, 0));

  arcQuad2.halfArcQuad[1].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.7f, -0.7f, 0));
  arcQuad2.halfArcQuad[1].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, -1.0f, 0));
  arcQuad2.halfArcQuad[1].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 0.0f, 0));

  arcQuad2.createBuffer();
  arcQuads.push_back(arcQuad2);
}

static void addS(
  Vector3D p, float angle, float scale,
  std::vector<ArcSegment>& arcSegments, 
  std::vector<ArcTriangle>& arcTriangles, 
  std::vector<ArcQuad>& arcQuads
) {

  // BBOX = MIN[-2.0f, -5.0f] MAX[2.0f, +2.0f]

  std::vector<Matrix4x4> matrixSequence;

  matrixSequence.push_back(UnifiedMath::translate(p));
  matrixSequence.push_back(UnifiedMath::rotate(angle, Vector3D(0.0f, 0.0f, 1.0f)));
  matrixSequence.push_back(UnifiedMath::scale(Vector3D(scale)));
  matrixSequence.push_back(UnifiedMath::translate(Vector3D(.0f, 0.5f, 0.0f)));

  Matrix4x4 shapeTransformation = UnifiedMath::matrixSequenceMultiply(matrixSequence);
  
  float s_width = 0.2f;

  float outer_radius = (0.5f + s_width / 2.0f) / 2.0f;
  float iner_radius = ((0.5f - s_width) - s_width / 2.0f) / 2.0f;

  Vector3D outer_center(0.0f, 0.5f - outer_radius, 0.0f);
  Vector3D iner_center(0.0f, 0.5f - s_width - iner_radius, 0.0f);

  ArcSegment arcSegment0, arcSegment1;

  arcSegment0.p1 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(outer_radius, outer_center.y, 0));
  arcSegment0.p2 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(iner_radius, iner_center.y, 0));
  arcSegment0.center = UnifiedMath::TransformWithTranslation(shapeTransformation, (0.5f * Vector3D(outer_radius + iner_radius, (iner_center.y + outer_center.y), 0.0f)));
  arcSegment0.createBuffer();
  arcSegments.push_back(arcSegment0);

  arcSegment1.p1 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-outer_radius, -outer_center.y, 0));
  arcSegment1.p2 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-iner_radius, -iner_center.y, 0));
  arcSegment1.center = UnifiedMath::TransformWithTranslation(shapeTransformation, (-0.5f * Vector3D(outer_radius + iner_radius, (iner_center.y + outer_center.y), 0.0f)));
  arcSegment1.createBuffer();
  arcSegments.push_back(arcSegment1);



  ArcQuad arcQuad0, arcQuad1, arcQuad2, arcQuad3;
  arcQuad0.halfArcQuad[0].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-outer_radius, outer_center.y, 0));
  arcQuad0.halfArcQuad[0].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( outer_radius, outer_center.y, 0));
  arcQuad0.halfArcQuad[0].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, outer_center);

  arcQuad0.halfArcQuad[1].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-iner_radius, iner_center.y, 0));
  arcQuad0.halfArcQuad[1].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( iner_radius, iner_center.y, 0));
  arcQuad0.halfArcQuad[1].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, iner_center);

  arcQuad0.createBuffer();
  arcQuads.push_back(arcQuad0);

  arcQuad1.halfArcQuad[0].p0 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, outer_center.y - outer_radius, 0));
  arcQuad1.halfArcQuad[0].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-outer_radius, outer_center.y, 0));
  arcQuad1.halfArcQuad[0].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, outer_center );

  arcQuad1.halfArcQuad[1].p0 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, iner_center.y - iner_radius, 0));
  arcQuad1.halfArcQuad[1].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-iner_radius,  iner_center.y,  0));
  arcQuad1.halfArcQuad[1].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, iner_center);

  arcQuad1.createBuffer();
  arcQuads.push_back(arcQuad1);

  arcQuad2.halfArcQuad[0].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, outer_center.y - outer_radius, 0));
  arcQuad2.halfArcQuad[0].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, -iner_center.y - iner_radius, 0));
  arcQuad2.halfArcQuad[0].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, -iner_center);

  arcQuad2.halfArcQuad[1].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, iner_center.y - iner_radius, 0));
  arcQuad2.halfArcQuad[1].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, -outer_center.y - outer_radius, 0));
  arcQuad2.halfArcQuad[1].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, -outer_center);

  arcQuad2.createBuffer();
  arcQuads.push_back(arcQuad2);

  arcQuad3.halfArcQuad[0].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-iner_radius, -iner_center.y, 0));
  arcQuad3.halfArcQuad[0].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, -iner_center.y - iner_radius, 0));
  arcQuad3.halfArcQuad[0].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, -iner_center);

  arcQuad3.halfArcQuad[1].p1      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-outer_radius, -outer_center.y, 0));
  arcQuad3.halfArcQuad[1].p0      = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, -outer_center.y - outer_radius, 0));
  arcQuad3.halfArcQuad[1].center  = UnifiedMath::TransformWithTranslation(shapeTransformation, -outer_center);

  arcQuad3.createBuffer();
  arcQuads.push_back(arcQuad3);
}

static void addT(
  Vector3D p, float angle, float scale,
  std::vector<ArcSegment>& arcSegments, 
  std::vector<ArcTriangle>& arcTriangles, 
  std::vector<ArcQuad>& arcQuads
) {

  // BBOX = MIN[-2.0f, 0.0f] MAX[2.0f, 5.6f]
  
  std::vector<Matrix4x4> matrixSequence;

  matrixSequence.push_back(UnifiedMath::translate(p));
  matrixSequence.push_back(UnifiedMath::rotate(angle, Vector3D(0.0f, 0.0f, 1.0f)));
  matrixSequence.push_back(UnifiedMath::scale(Vector3D(scale)));
  matrixSequence.push_back(UnifiedMath::translate(Vector3D(.0f, 0.5f, 0.0f)));
  matrixSequence.push_back(UnifiedMath::scale(Vector3D(1.0f / 4.0f, 1.0f / 5.6f, 1.0f)));
  matrixSequence.push_back(UnifiedMath::translate(Vector3D(0.0f, -2.8, 0.0f)));


  Matrix4x4 shapeTransformation = UnifiedMath::matrixSequenceMultiply(matrixSequence);

  // (-2.0f, -3.0f) => (2.0f, 1.2f) 

  ArcTriangle arcTriangle0, arcTriangle1;
  arcTriangle0.p1 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-2.0f, 4.1f, 0));
  arcTriangle0.p2 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-1.0f, 4.0f, 0));
  arcTriangle0.p3 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-1.8f, 4.2f, 0));
  arcTriangle0.center = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-1.4f, 4.2f, 0));
  arcTriangles.push_back(arcTriangle0);

  arcTriangle1.p1 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.0f, 4.0f, 0));
  arcTriangle1.p2 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(2.0f, 4.1f, 0));
  arcTriangle1.p3 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.8f, 4.2f, 0));
  arcTriangle1.center = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(1.4f, 4.2f, 0));
  arcTriangles.push_back(arcTriangle1);

  ArcQuad arcQuad0, arcQuad1;
  arcQuad0.halfArcQuad[0].p0 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-1.8f, 4.2f, 0));
  arcQuad0.halfArcQuad[0].p1 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(+1.8f, 4.2f, 0));
  arcQuad0.halfArcQuad[0].p1 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(+1.8f, 4.2f, 0));
  arcQuad0.halfArcQuad[0].center = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 3.0f, 0));

  arcQuad0.halfArcQuad[1].p0 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-1.0f, 4.0f, 0));
  arcQuad0.halfArcQuad[1].p1 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(+1.0f, 4.0f, 0));
  arcQuad0.halfArcQuad[1].center = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 3.0f, 0));

  arcQuad0.createBuffer();
  arcQuads.push_back(arcQuad0);

  arcQuad1.halfArcQuad[0].p0 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-0.4f, 4.0f, 0));
  arcQuad1.halfArcQuad[0].p1 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D( 0.4f, 4.0f, 0));
  arcQuad1.halfArcQuad[0].center = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, 3.0f, 0));

  arcQuad1.halfArcQuad[1].p0 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(-0.2f, 0.0f, 0));
  arcQuad1.halfArcQuad[1].p1 = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.2f, 0.0f, 0));
  arcQuad1.halfArcQuad[1].center = UnifiedMath::TransformWithTranslation(shapeTransformation, Vector3D(0.0f, -1.0f, 0));

  arcQuad1.createBuffer();
  arcQuads.push_back(arcQuad1);
}

static void addM(
  std::vector<ArcSegment>& arcSegments, 
  std::vector<ArcTriangle>& arcTriangles, 
  std::vector<ArcQuad>& arcQuads
) {
  ArcQuad arcQuad0, arcQuad1, arcQuad2;
  arcQuad0.halfArcQuad[1].p0 = Vector3D(+1.4f, 1.4f, 0);
  arcQuad0.halfArcQuad[1].p1 = Vector3D(-1.4f, 1.4f, 0);
  arcQuad0.halfArcQuad[1].center = Vector3D(0.0f, 0.0f, 0);

  arcQuad0.halfArcQuad[0].p0 = Vector3D(+1.4f, 1.0f, 0);
  arcQuad0.halfArcQuad[0].p1 = Vector3D(-1.4f, 1.0f, 0);
  arcQuad0.halfArcQuad[0].center = Vector3D(0.0f, 0.0f, 0);

  arcQuad0.createBuffer();
  arcQuads.push_back(arcQuad0);

  arcQuad1.halfArcQuad[0].p0 = Vector3D(+1.8f, +1.4f, 0);
  arcQuad1.halfArcQuad[0].p1 = Vector3D(+1.4f, +1.4f, 0);
  arcQuad1.halfArcQuad[0].center = Vector3D(+1.6f, 1.6f, 0);

  arcQuad1.halfArcQuad[1].p0 = Vector3D(+1.8f, -2.0f, 0);
  arcQuad1.halfArcQuad[1].p1 = Vector3D(+1.4f, -2.0f, 0);
  arcQuad1.halfArcQuad[1].center = Vector3D(+1.6f, -1.8f, 0);

  arcQuad1.createBuffer();
  arcQuads.push_back(arcQuad1);

  arcQuad2.halfArcQuad[0].p0 = Vector3D(-1.4f, +1.4f, 0);
  arcQuad2.halfArcQuad[0].p1 = Vector3D(-1.8f, +1.4f, 0);
  arcQuad2.halfArcQuad[0].center = Vector3D(-1.6f, 1.6f, 0);

  arcQuad2.halfArcQuad[1].p0 = Vector3D(-1.4f, -2.0f, 0);
  arcQuad2.halfArcQuad[1].p1 = Vector3D(-1.8f, -2.0f, 0);
  arcQuad2.halfArcQuad[1].center = Vector3D(-1.6f, -1.8f, 0);

  arcQuad2.createBuffer();
  arcQuads.push_back(arcQuad2);
}

static void addF(
  std::vector<ArcSegment>& arcSegments, 
  std::vector<ArcTriangle>& arcTriangles, 
  std::vector<ArcQuad>& arcQuads
) {
  ArcQuad arcQuad0, arcQuad1, arcQuad2;
  arcQuad0.halfArcQuad[0].p0 = Vector3D(-2.0f, 2.0f, 0);
  arcQuad0.halfArcQuad[0].p1 = Vector3D(+2.0f, 2.0f, 0);
  arcQuad0.halfArcQuad[0].center = Vector3D(0.0f, 2.3f, 0);

  arcQuad0.halfArcQuad[1].p0 = Vector3D(-2.0f, 1.4f, 0);
  arcQuad0.halfArcQuad[1].p1 = Vector3D(+2.0f, 1.4f, 0);
  arcQuad0.halfArcQuad[1].center = Vector3D(0.0f, 29.5f, 0);

  arcQuad0.createBuffer();
  arcQuads.push_back(arcQuad0);

  arcQuad1.halfArcQuad[0].p0 = Vector3D(+1.0f, -0.5f, 0);
  arcQuad1.halfArcQuad[0].p1 = Vector3D(-2.0f, -0.5f, 0);
  arcQuad1.halfArcQuad[0].center = Vector3D(-0.5f, -0.7f, 0);

  arcQuad1.halfArcQuad[1].p0 = Vector3D(+1.0f, -1.0f, 0);
  arcQuad1.halfArcQuad[1].p1 = Vector3D(-2.0f, -1.0f, 0);
  arcQuad1.halfArcQuad[1].center = Vector3D(-0.5f, -1.3f, 0);

  arcQuad1.createBuffer();
  arcQuads.push_back(arcQuad1);
  
  arcQuad2.halfArcQuad[0].p0 = Vector3D(-2.4f, +2.0f, 0);
  arcQuad2.halfArcQuad[0].p1 = Vector3D(-2.0f, +2.0f, 0);
  arcQuad2.halfArcQuad[0].center = Vector3D(-2.2f, 3.0f, 0);

  arcQuad2.halfArcQuad[1].p0 = Vector3D(-2.4f, -4.0f, 0);
  arcQuad2.halfArcQuad[1].p1 = Vector3D(-2.0f, -4.0f, 0);
  arcQuad2.halfArcQuad[1].center = Vector3D(-2.2f, -5.0f, 0);

  arcQuad2.createBuffer();
  arcQuads.push_back(arcQuad2);
}

static void addCST(
  Vector3D p, float angle, float scale,
  std::vector<ArcSegment>&   arcSegments,
  std::vector<ArcTriangle>&  arcTriangles, 
  std::vector<ArcQuad>&      arcQuads) {

  addC(p + scale * Vector3D(-1.0f, 0.0f, 0.0f), angle, scale, arcSegments, arcTriangles, arcQuads);
  addS(p + scale * Vector3D(0.0f, 0.0f, 0.0f),  angle, scale, arcSegments, arcTriangles, arcQuads);
  addT(p + scale * Vector3D(1.0f, 0.0f, 0.0f),  angle, scale, arcSegments, arcTriangles, arcQuads);

}

static void sampleDataGenerator(std::vector<ArcSegment>& arcSegs, std::vector<ArcTriangle> arcTriangles, std::vector<ArcQuad>& arcQuads) {

}

#endif // __SAMPLE_DATA_GENERATOR_H__