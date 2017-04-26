bool track(int signature) {
  uint16_t blocks;
  blocks = pixy.getBlocks();
  if (blocks){
    int trackedBlock = TrackBlock(blocks, signature);
    
    if(trackedBlock == -1)
      return false;
      
    blobSize = pixy.blocks[trackedBlock].width * pixy.blocks[trackedBlock].height;
    blob_x = pixy.blocks[trackedBlock].x;
    blob_y = pixy.blocks[trackedBlock].y;
   
    if(blobSize > MIN_BLOB_SIZE) {
      FollowBlock(trackedBlock);
      return true;
    }
  }
  
  return false;
}
