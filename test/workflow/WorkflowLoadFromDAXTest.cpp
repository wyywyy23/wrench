/**
 * Copyright (c) 2017. The WRENCH Team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

#include <gtest/gtest.h>

#include "wrench/workflow/Workflow.h"

class WorkflowLoadFromDAXTest : public ::testing::Test {
protected:
    WorkflowLoadFromDAXTest() {

      std::string xml =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
              "<!-- generated: 2008-10-10T17:09:38-07:00 -->"
              "<!-- generated by: shishir [??] -->"
              "<adag xmlns=\"http://pegasus.isi.edu/schema/DAX\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://pegasus.isi.edu/schema/DAX http://pegasus.isi.edu/schema/dax-2.1.xsd\" version=\"2.1\" count=\"1\" index=\"0\" name=\"test\" jobCount=\"36\" fileCount=\"0\" childCount=\"35\">"
              "<!-- part 1: list of all referenced files (may be empty) -->"
              "<!-- part 2: definition of all jobs (at least one) -->"
              "  <job id=\"ID00000\" namespace=\"Genome\" name=\"fastqSplit_chr21\" version=\"1.0\" runtime=\"35.79\" num_procs=\"3\">"
              "    <uses file=\"chr210.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"249228055\"/>"
              "    <uses file=\"chr21.0.0.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"30755085\"/>"
              "    <uses file=\"chr21.0.1.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"31101555\"/>"
              "    <uses file=\"chr21.0.2.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"30523391\"/>"
              "    <uses file=\"chr21.0.3.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"30859556\"/>"
              "    <uses file=\"chr21.0.4.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"32376817\"/>"
              "    <uses file=\"chr21.0.5.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"31630160\"/>"
              "    <uses file=\"chr21.0.6.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"32262778\"/>"
              "    <uses file=\"chr21.0.7.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"29718713\"/>"
              "  </job>"
              "  <job id=\"ID00001\" namespace=\"Genome\" name=\"filterContams_chr21\" version=\"1.0\" runtime=\"2.82\">"
              "    <uses file=\"chr21.0.0.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"30755085\"/>"
              "    <uses file=\"chr21.0.0.nocontam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15551340\"/>"
              "    <uses file=\"chr21.0.0.contam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15203745\"/>"
              "  </job>"
              "  <job id=\"ID00002\" namespace=\"Genome\" name=\"filterContams_chr21\" version=\"1.0\" runtime=\"2.68\">"
              "    <uses file=\"chr21.0.1.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"31101555\"/>"
              "    <uses file=\"chr21.0.1.nocontam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15501194\"/>"
              "    <uses file=\"chr21.0.1.contam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15600361\"/>"
              "  </job>"
              "  <job id=\"ID00003\" namespace=\"Genome\" name=\"filterContams_chr21\" version=\"1.0\" runtime=\"2.75\">"
              "    <uses file=\"chr21.0.2.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"30523391\"/>"
              "    <uses file=\"chr21.0.2.nocontam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15223514\"/>"
              "    <uses file=\"chr21.0.2.contam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15299877\"/>"
              "  </job>"
              "  <job id=\"ID00004\" namespace=\"Genome\" name=\"filterContams_chr21\" version=\"1.0\" runtime=\"4.56\">"
              "    <uses file=\"chr21.0.3.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"30859556\"/>"
              "    <uses file=\"chr21.0.3.nocontam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"14781819\"/>"
              "    <uses file=\"chr21.0.3.contam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"16077737\"/>"
              "  </job>"
              "  <job id=\"ID00005\" namespace=\"Genome\" name=\"filterContams_chr21\" version=\"1.0\" runtime=\"4.12\">"
              "    <uses file=\"chr21.0.4.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"32376817\"/>"
              "    <uses file=\"chr21.0.4.nocontam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15467155\"/>"
              "    <uses file=\"chr21.0.4.contam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"16909662\"/>"
              "  </job>"
              "  <job id=\"ID00006\" namespace=\"Genome\" name=\"filterContams_chr21\" version=\"1.0\" runtime=\"5.51\">"
              "    <uses file=\"chr21.0.5.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"31630160\"/>"
              "    <uses file=\"chr21.0.5.nocontam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15570955\"/>"
              "    <uses file=\"chr21.0.5.contam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"16059205\"/>"
              "  </job>"
              "  <job id=\"ID00007\" namespace=\"Genome\" name=\"filterContams_chr21\" version=\"1.0\" runtime=\"2.55\">"
              "    <uses file=\"chr21.0.6.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"32262778\"/>"
              "    <uses file=\"chr21.0.6.nocontam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15344899\"/>"
              "    <uses file=\"chr21.0.6.contam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"16917879\"/>"
              "  </job>"
              "  <job id=\"ID00008\" namespace=\"Genome\" name=\"filterContams_chr21\" version=\"1.0\" runtime=\"3.65\">"
              "    <uses file=\"chr21.0.7.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"29718713\"/>"
              "    <uses file=\"chr21.0.7.nocontam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15327292\"/>"
              "    <uses file=\"chr21.0.7.contam.sfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"14391421\"/>"
              "  </job>"
              "  <job id=\"ID00009\" namespace=\"Genome\" name=\"sol2sanger_chr21\" version=\"1.0\" runtime=\"1.09\">"
              "    <uses file=\"chr21.0.0.nocontam.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15551340\"/>"
              "    <uses file=\"chr21.0.0.nocontam.fq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"10643786\"/>"
              "  </job>"
              "  <job id=\"ID00010\" namespace=\"Genome\" name=\"sol2sanger_chr21\" version=\"1.0\" runtime=\"1.28\">"
              "    <uses file=\"chr21.0.1.nocontam.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15501194\"/>"
              "    <uses file=\"chr21.0.1.nocontam.fq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"10587125\"/>"
              "  </job>"
              "  <job id=\"ID00011\" namespace=\"Genome\" name=\"sol2sanger_chr21\" version=\"1.0\" runtime=\"0.82\">"
              "    <uses file=\"chr21.0.2.nocontam.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15223514\"/>"
              "    <uses file=\"chr21.0.2.nocontam.fq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"11218923\"/>"
              "  </job>"
              "  <job id=\"ID00012\" namespace=\"Genome\" name=\"sol2sanger_chr21\" version=\"1.0\" runtime=\"1.12\">"
              "    <uses file=\"chr21.0.3.nocontam.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"14781819\"/>"
              "    <uses file=\"chr21.0.3.nocontam.fq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"10988665\"/>"
              "  </job>"
              "  <job id=\"ID00013\" namespace=\"Genome\" name=\"sol2sanger_chr21\" version=\"1.0\" runtime=\"0.91\">"
              "    <uses file=\"chr21.0.4.nocontam.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15467155\"/>"
              "    <uses file=\"chr21.0.4.nocontam.fq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"9278703\"/>"
              "  </job>"
              "  <job id=\"ID00014\" namespace=\"Genome\" name=\"sol2sanger_chr21\" version=\"1.0\" runtime=\"1.40\">"
              "    <uses file=\"chr21.0.5.nocontam.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15570955\"/>"
              "    <uses file=\"chr21.0.5.nocontam.fq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"8913290\"/>"
              "  </job>"
              "  <job id=\"ID00015\" namespace=\"Genome\" name=\"sol2sanger_chr21\" version=\"1.0\" runtime=\"1.20\">"
              "    <uses file=\"chr21.0.6.nocontam.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15344899\"/>"
              "    <uses file=\"chr21.0.6.nocontam.fq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"14769501\"/>"
              "  </job>"
              "  <job id=\"ID00016\" namespace=\"Genome\" name=\"sol2sanger_chr21\" version=\"1.0\" runtime=\"0.90\">"
              "    <uses file=\"chr21.0.7.nocontam.sfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"15327292\"/>"
              "    <uses file=\"chr21.0.7.nocontam.fq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"20129851\"/>"
              "  </job>"
              "  <job id=\"ID00017\" namespace=\"Genome\" name=\"fastq2bfq_chr21\" version=\"1.0\" runtime=\"1.48\">"
              "    <uses file=\"chr21.0.0.nocontam.fq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"10643786\"/>"
              "    <uses file=\"chr21.0.0.nocontam.bfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2687881\"/>"
              "  </job>"
              "  <job id=\"ID00018\" namespace=\"Genome\" name=\"fastq2bfq_chr21\" version=\"1.0\" runtime=\"2.03\">"
              "    <uses file=\"chr21.0.1.nocontam.fq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"10587125\"/>"
              "    <uses file=\"chr21.0.1.nocontam.bfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2675372\"/>"
              "  </job>"
              "  <job id=\"ID00019\" namespace=\"Genome\" name=\"fastq2bfq_chr21\" version=\"1.0\" runtime=\"1.52\">"
              "    <uses file=\"chr21.0.2.nocontam.fq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"11218923\"/>"
              "    <uses file=\"chr21.0.2.nocontam.bfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2747920\"/>"
              "  </job>"
              "  <job id=\"ID00020\" namespace=\"Genome\" name=\"fastq2bfq_chr21\" version=\"1.0\" runtime=\"1.39\">"
              "    <uses file=\"chr21.0.3.nocontam.fq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"10988665\"/>"
              "    <uses file=\"chr21.0.3.nocontam.bfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2595541\"/>"
              "  </job>"
              "  <job id=\"ID00021\" namespace=\"Genome\" name=\"fastq2bfq_chr21\" version=\"1.0\" runtime=\"1.49\">"
              "    <uses file=\"chr21.0.4.nocontam.fq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"9278703\"/>"
              "    <uses file=\"chr21.0.4.nocontam.bfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2723507\"/>"
              "  </job>"
              "  <job id=\"ID00022\" namespace=\"Genome\" name=\"fastq2bfq_chr21\" version=\"1.0\" runtime=\"1.70\">"
              "    <uses file=\"chr21.0.5.nocontam.fq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"8913290\"/>"
              "    <uses file=\"chr21.0.5.nocontam.bfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2146361\"/>"
              "  </job>"
              "  <job id=\"ID00023\" namespace=\"Genome\" name=\"fastq2bfq_chr21\" version=\"1.0\" runtime=\"2.31\">"
              "    <uses file=\"chr21.0.6.nocontam.fq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"14769501\"/>"
              "    <uses file=\"chr21.0.6.nocontam.bfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2955840\"/>"
              "  </job>"
              "  <job id=\"ID00024\" namespace=\"Genome\" name=\"fastq2bfq_chr21\" version=\"1.0\" runtime=\"3.22\">"
              "    <uses file=\"chr21.0.7.nocontam.fq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"20129851\"/>"
              "    <uses file=\"chr21.0.7.nocontam.bfq\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"4532910\"/>"
              "  </job>"
              "  <job id=\"ID00025\" namespace=\"Genome\" name=\"map_chr21\" version=\"1.0\" runtime=\"12515.26\">"
              "    <uses file=\"chr21.BS.bfa\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"5079934029\"/>"
              "    <uses file=\"chr21.0.0.nocontam.bfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2687881\"/>"
              "    <uses file=\"chr21.0.0.nocontam.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2921609\"/>"
              "  </job>"
              "  <job id=\"ID00026\" namespace=\"Genome\" name=\"map_chr21\" version=\"1.0\" runtime=\"11306.73\">"
              "    <uses file=\"chr21.BS.bfa\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"5079934029\"/>"
              "    <uses file=\"chr21.0.1.nocontam.bfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2675372\"/>"
              "    <uses file=\"chr21.0.1.nocontam.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2908013\"/>"
              "  </job>"
              "  <job id=\"ID00027\" namespace=\"Genome\" name=\"map_chr21\" version=\"1.0\" runtime=\"11078.40\">"
              "    <uses file=\"chr21.BS.bfa\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"5079934029\"/>"
              "    <uses file=\"chr21.0.2.nocontam.bfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2747920\"/>"
              "    <uses file=\"chr21.0.2.nocontam.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2986869\"/>"
              "  </job>"
              "  <job id=\"ID00028\" namespace=\"Genome\" name=\"map_chr21\" version=\"1.0\" runtime=\"17502.41\">"
              "    <uses file=\"chr21.BS.bfa\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"5079934029\"/>"
              "    <uses file=\"chr21.0.3.nocontam.bfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2595541\"/>"
              "    <uses file=\"chr21.0.3.nocontam.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2821240\"/>"
              "  </job>"
              "  <job id=\"ID00029\" namespace=\"Genome\" name=\"map_chr21\" version=\"1.0\" runtime=\"11710.28\">"
              "    <uses file=\"chr21.BS.bfa\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"5079934029\"/>"
              "    <uses file=\"chr21.0.4.nocontam.bfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2723507\"/>"
              "    <uses file=\"chr21.0.4.nocontam.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2960333\"/>"
              "  </job>"
              "  <job id=\"ID00030\" namespace=\"Genome\" name=\"map_chr21\" version=\"1.0\" runtime=\"9737.47\">"
              "    <uses file=\"chr21.BS.bfa\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"5079934029\"/>"
              "    <uses file=\"chr21.0.5.nocontam.bfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2146361\"/>"
              "    <uses file=\"chr21.0.5.nocontam.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2333001\"/>"
              "  </job>"
              "  <job id=\"ID00031\" namespace=\"Genome\" name=\"map_chr21\" version=\"1.0\" runtime=\"15270.31\">"
              "    <uses file=\"chr21.BS.bfa\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"5079934029\"/>"
              "    <uses file=\"chr21.0.6.nocontam.bfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2955840\"/>"
              "    <uses file=\"chr21.0.6.nocontam.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"3212869\"/>"
              "  </job>"
              "  <job id=\"ID00032\" namespace=\"Genome\" name=\"map_chr21\" version=\"1.0\" runtime=\"18918.69\">"
              "    <uses file=\"chr21.BS.bfa\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"5079934029\"/>"
              "    <uses file=\"chr21.0.7.nocontam.bfq\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"4532910\"/>"
              "    <uses file=\"chr21.0.7.nocontam.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"4927076\"/>"
              "  </job>"
              "  <job id=\"ID00033\" namespace=\"Genome\" name=\"mapMerge_chr21\" version=\"1.0\" runtime=\"12.04\">"
              "    <uses file=\"chr21.0.0.nocontam.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2921609\"/>"
              "    <uses file=\"chr21.0.1.nocontam.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2908013\"/>"
              "    <uses file=\"chr21.0.2.nocontam.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2986869\"/>"
              "    <uses file=\"chr21.0.3.nocontam.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2821240\"/>"
              "    <uses file=\"chr21.0.4.nocontam.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2960333\"/>"
              "    <uses file=\"chr21.0.5.nocontam.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"2333001\"/>"
              "    <uses file=\"chr21.0.6.nocontam.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"3212869\"/>"
              "    <uses file=\"chr21.0.7.nocontam.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"4927076\"/>"
              "    <uses file=\"chr21.nocontam.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"23651896\"/>"
              "    <uses file=\"chr21.nocontam.map.zr\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"685450\"/>"
              "    <uses file=\"chr21.nocontam.map.vm\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"143449\"/>"
              "  </job>"
              "  <job id=\"ID00034\" namespace=\"Genome\" name=\"maqindex_chr21\" version=\"1.0\" runtime=\"0.02\">"
              "    <uses file=\"chr21.nocontam.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"23651896\"/>"
              "    <uses file=\"chr21.nocontam.chr.map\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"352515\"/>"
              "  </job>"
              "  <job id=\"ID00035\" namespace=\"Genome\" name=\"pileup_chr21\" version=\"1.0\" runtime=\"5659.46\">"
              "    <uses file=\"chr21.BSnull.bfa\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"5079934029\"/>"
              "    <uses file=\"chr21.nocontam.chr.map\" link=\"input\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"352515\"/>"
              "    <uses file=\"chr21.nocontam.chr.pileup\" link=\"output\" register=\"true\" transfer=\"true\" optional=\"false\" type=\"data\" size=\"1489885\"/>"
              "  </job>"
              "<!-- part 3: list of control-flow dependencies (may be empty) -->"
              "  <child ref=\"ID00001\">"
              "    <parent ref=\"ID00000\"/>"
              "  </child>"
              "  <child ref=\"ID00002\">"
              "    <parent ref=\"ID00000\"/>"
              "  </child>"
              "  <child ref=\"ID00003\">"
              "    <parent ref=\"ID00000\"/>"
              "  </child>"
              "  <child ref=\"ID00004\">"
              "    <parent ref=\"ID00000\"/>"
              "  </child>"
              "  <child ref=\"ID00005\">"
              "    <parent ref=\"ID00000\"/>"
              "  </child>"
              "  <child ref=\"ID00006\">"
              "    <parent ref=\"ID00000\"/>"
              "  </child>"
              "  <child ref=\"ID00007\">"
              "    <parent ref=\"ID00000\"/>"
              "  </child>"
              "  <child ref=\"ID00008\">"
              "    <parent ref=\"ID00000\"/>"
              "  </child>"
              "  <child ref=\"ID00009\">"
              "    <parent ref=\"ID00001\"/>"
              "  </child>"
              "  <child ref=\"ID00010\">"
              "    <parent ref=\"ID00002\"/>"
              "  </child>"
              "  <child ref=\"ID00011\">"
              "    <parent ref=\"ID00003\"/>"
              "  </child>"
              "  <child ref=\"ID00012\">"
              "    <parent ref=\"ID00004\"/>"
              "  </child>"
              "  <child ref=\"ID00013\">"
              "    <parent ref=\"ID00005\"/>"
              "  </child>"
              "  <child ref=\"ID00014\">"
              "    <parent ref=\"ID00006\"/>"
              "  </child>"
              "  <child ref=\"ID00015\">"
              "    <parent ref=\"ID00007\"/>"
              "  </child>"
              "  <child ref=\"ID00016\">"
              "    <parent ref=\"ID00008\"/>"
              "  </child>"
              "  <child ref=\"ID00017\">"
              "    <parent ref=\"ID00009\"/>"
              "  </child>"
              "  <child ref=\"ID00018\">"
              "    <parent ref=\"ID00010\"/>"
              "  </child>"
              "  <child ref=\"ID00019\">"
              "    <parent ref=\"ID00011\"/>"
              "  </child>"
              "  <child ref=\"ID00020\">"
              "    <parent ref=\"ID00012\"/>"
              "  </child>"
              "  <child ref=\"ID00021\">"
              "    <parent ref=\"ID00013\"/>"
              "  </child>"
              "  <child ref=\"ID00022\">"
              "    <parent ref=\"ID00014\"/>"
              "  </child>"
              "  <child ref=\"ID00023\">"
              "    <parent ref=\"ID00015\"/>"
              "  </child>"
              "  <child ref=\"ID00024\">"
              "    <parent ref=\"ID00016\"/>"
              "  </child>"
              "  <child ref=\"ID00025\">"
              "    <parent ref=\"ID00017\"/>"
              "  </child>"
              "  <child ref=\"ID00026\">"
              "    <parent ref=\"ID00018\"/>"
              "  </child>"
              "  <child ref=\"ID00027\">"
              "    <parent ref=\"ID00019\"/>"
              "  </child>"
              "  <child ref=\"ID00028\">"
              "    <parent ref=\"ID00020\"/>"
              "  </child>"
              "  <child ref=\"ID00029\">"
              "    <parent ref=\"ID00021\"/>"
              "  </child>"
              "  <child ref=\"ID00030\">"
              "    <parent ref=\"ID00022\"/>"
              "  </child>"
              "  <child ref=\"ID00031\">"
              "    <parent ref=\"ID00023\"/>"
              "  </child>"
              "  <child ref=\"ID00032\">"
              "    <parent ref=\"ID00024\"/>"
              "  </child>"
              "  <child ref=\"ID00033\">"
              "    <parent ref=\"ID00032\"/>"
              "    <parent ref=\"ID00030\"/>"
              "    <parent ref=\"ID00031\"/>"
              "    <parent ref=\"ID00025\"/>"
              "    <parent ref=\"ID00026\"/>"
              "    <parent ref=\"ID00027\"/>"
              "    <parent ref=\"ID00028\"/>"
              "    <parent ref=\"ID00029\"/>"
              "  </child>"
              "  <child ref=\"ID00034\">"
              "    <parent ref=\"ID00033\"/>"
              "  </child>"
              "  <child ref=\"ID00035\">"
              "    <parent ref=\"ID00034\"/>"
              "  </child>"
              "</adag>"
              ;

      FILE *dax_file = fopen(dax_file_path.c_str(), "w");
      fprintf(dax_file, "%s", xml.c_str());
      fclose(dax_file);
    }

    // data members
    std::string dax_file_path = "/tmp/workflow.dax";
};

TEST_F(WorkflowLoadFromDAXTest, LoadValidDAX) {

  auto *workflow = new wrench::Workflow();

  EXPECT_THROW(workflow->loadFromDAX("bogus", "1f"), std::invalid_argument);
  EXPECT_NO_THROW(workflow->loadFromDAX(this->dax_file_path, "1f"));
  ASSERT_EQ(workflow->getNumberOfTasks(), 36);
  ASSERT_EQ(workflow->getFiles().size(), 56);

  unsigned long num_input_files = workflow->getWorkflowTaskByID("ID00000")->getInputFiles().size();
  unsigned long num_output_files = workflow->getWorkflowTaskByID("ID00000")->getOutputFiles().size();

  ASSERT_EQ(num_input_files, 1);
  ASSERT_EQ(num_output_files, 8);

  ASSERT_NEAR(workflow->getWorkflowTaskByID("ID00000")->getFlops(), 35.79, 0.001);
  ASSERT_EQ(workflow->getWorkflowTaskByID("ID00000")->getMinNumCores(), 1);
  ASSERT_EQ(workflow->getWorkflowTaskByID("ID00000")->getMaxNumCores(), 3);


}


