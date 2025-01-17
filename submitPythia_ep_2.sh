#!/bin/bash

#SBATCH --time=2:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --job-name=Pythia_ep
#SBATCH --account=PAS2524
#####SBATCH --mail.type=BEGIN,END,FAIL
#SBATCH --output=output2/stdout/%j.out
#SBATCH --error=output2/stderr/%j.err

####sbcast $HOME/eic/local/lib/jug_xl-nightly/ $TMPDIR/local/lib/jug_xl-nightly
sbcast $HOME/eic/eic-shell $TMPDIR/eic-shell
sbcast $SLURM_SUBMIT_DIR/runBatch.sh $TMPDIR/runBatch.sh
sbcast $SLURM_SUBMIT_DIR/ep_diffractiveDiJets.cmnd $TMPDIR/ep_diffractiveDiJets.cmnd
sbcast $SLURM_SUBMIT_DIR/pythiaDiffractiveDiJet $TMPDIR/pythiaDiffractiveDiJet
sbcast $SLURM_SUBMIT_DIR/DictOutput_rdict.pcm $TMPDIR/DictOutput_rdict.pcm
sbcast $SLURM_SUBMIT_DIR/libPythiaEvent.so $TMPDIR/libPythiaEvent.so

#mkdir $TMPDIR/output
#mkdir $TMPDIR/tree

module load singularity 
cd $TMPDIR
mkdir $TMPDIR/local
mkdir $TMPDIR/local/lib
#srun -n $SLURM_JOB_NUM_NODES --ntasks-per-node=1 cp -r $HOME/eic/local/lib/jug_xl-nightly $TMPDIR/local/lib/
srun -n $SLURM_JOB_NUM_NODES --ntasks-per-node=1 cp -r $HOME/eic/local/lib/jug_xl-testing.sif $TMPDIR/local/lib/
ls
ls $TMPDIR/local/
ls $TMPDIR/local/*
#./eic-shell -- ./runBatch.sh $SLURM_ARRAY_TASK_ID
#./eic-shell -- ./runBatch.sh
apptainer run $TMPDIR/local/lib/jug_xl-testing.sif -- ./runBatch.sh

cp $TMPDIR/diffractiveDiJets_ep_18x275GeV_hist.root $SLURM_SUBMIT_DIR/output2/output/diffractiveDiJets_ep_18x275GeV_${SLURM_ARRAY_TASK_ID}_hist.root
cp $TMPDIR/diffractiveDiJets_ep_18x275GeV_tree.root $SLURM_SUBMIT_DIR/output2/tree/diffractiveDiJets_ep_18x275GeV_${SLURM_ARRAY_TASK_ID}_tree.root
cp $TMPDIR/diffractiveDiJets_ep_18x275GeV.hepmc3 $SLURM_SUBMIT_DIR/output2/hepmc/diffractiveDiJets_ep_18x275GeV_${SLURM_ARRAY_TASK_ID}.hepmc3


#sgather -k $TMPDIR/diffractiveDiJets_ep_18x275GeV_hist.root $SLURM_SUBMIT_DIR/output/output/diffractiveDiJets_ep_18x275GeV_${SLURM_ARRAY_TASK_ID}_hist.root
#sgather -k $TMPDIR/diffractiveDiJets_ep_18x275GeV_tree.root $SLURM_SUBMIT_DIR/output/tree/diffractiveDiJets_ep_18x275GeV_${SLURM_ARRAY_TASK_ID}_tree.root
#sgather -k $TMPDIR/diffractiveDiJets_ep_18x275GeV.hepmc3 $SLURM_SUBMIT_DIR/output/hepmc/diffractiveDiJets_ep_18x275GeV_${SLURM_ARRAY_TASK_ID}.hepmc3

#sgather -k $TMPDIR/diffractiveDiJets_ep_18x275GeV_$SLURM_ARRAY_TASK_ID_hist.root $SLURM_SUBMIT_DIR/output/output/diffractiveDiJets_ep_18x275GeV_$SLURM_ARRAY_TASK_ID_hist.root
#sgather -k $TMPDIR/diffractiveDiJets_ep_18x275GeV_$SLURM_ARRAY_TASK_ID_tree.root $SLURM_SUBMIT_DIR/output/tree/diffractiveDiJets_ep_18x275GeV_$SLURM_ARRAY_TASK_ID_tree.root
#sgather -k $TMPDIR/diffractiveDiJets_ep_18x275GeV_$SLURM_ARRAY_TASK_ID.hepmc3 $SLURM_SUBMIT_DIR/output/hepmc/diffractiveDiJets_ep_18x275GeV_$SLURM_ARRAY_TASK_ID.hepmc3

#sbatch --array=1-200 --account=PAS2524 submitPythia_ep.sh | tee submit.log