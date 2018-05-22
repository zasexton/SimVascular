/* Copyright (c) Stanford University, The Regents of the University of
 *               California, and others.
 *
 * All Rights Reserved.
 *
 * See Copyright-SimVascular.txt for additional details.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SV4GUI_SIMULATIONUTILS_H
#define SV4GUI_SIMULATIONUTILS_H

#include <sv4guiModuleSimulationExports.h>

#include "sv4gui_SimJob.h"

#include <string>
#include <vector>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkUnstructuredGrid.h>

class SV4GUIMODULESIMULATION_EXPORT sv4guiSimulationUtils
{

public:

    static std::string CreatePreSolverFileContent(sv4guiSimJob* job, std::string outputDir="");

    static std::string CreateRCRTFileContent(sv4guiSimJob* job);

    static std::string CreateCORTFileContent(sv4guiSimJob* job);

    static std::string CreateFlowSolverFileContent(sv4guiSimJob* job);

    static bool CreateFlowFiles(std::string outFlowFilePath, std::string outPressureFlePath
                                                   , std::string outAverageFilePath, std::string outAverageUnitsFilePath
                                                   , std::vector<std::string> vtxFilePaths, bool useComboFile
                                                   , std::string meshFaceDir, std::vector<std::string> meshFaceFileNames
                                                   , std::string unit, bool skipWalls);

    static void VtpExtractSingleFace(std::string step, vtkSmartPointer<vtkPolyData> simvtp,vtkSmartPointer<vtkPolyData> facevtp);

    static void VtuExtractSingleFace(std::string step, vtkSmartPointer<vtkUnstructuredGrid> simug,vtkSmartPointer<vtkPolyData> facevtp);

    static void VtpIntegrateFace(vtkSmartPointer<vtkPolyData>facevtp, std::map<std::string, double>& pmap, std::map<std::string, double>& qmap, std::map<std::string, double>& amap);
};

#endif /* SV4GUI_SIMULATIONUTILS_H */