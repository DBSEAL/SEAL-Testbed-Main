from ultralytics.data.converter import convert_coco

# labels_dir = folder that CONTAINS your COCO json files
convert_coco(
    labels_dir="taco/annotations",
    save_dir="taco_yolo",        # output folder (you choose)
    use_segments=True,           # IMPORTANT for masks
    use_keypoints=False,
    cls91to80=False              # keep your dataset's category ids as-is
)
