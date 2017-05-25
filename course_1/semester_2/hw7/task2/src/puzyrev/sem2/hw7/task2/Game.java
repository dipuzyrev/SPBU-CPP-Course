package puzyrev.sem2.hw7.task2;

import javafx.scene.Node;
import javafx.scene.control.Label;
import java.util.ArrayList;

public class Game {
    private boolean ended = false;

    private enum Value {
        CROSS,
        ZERO
    }

    private ArrayList<Label> crosses;
    private ArrayList<Label> zeros;
    private Label last = null;

    public Game() {
        crosses = new ArrayList<>();
        zeros = new ArrayList<>();
    }

    public String putValue(Label field) {
        if (!ended && field.getText().equals("")) {
            Value type = getType();
            addValue(type, field);

            String text = (type == Value.CROSS) ? "X" : "O";
            return text;
        } else {
            return null;
        }
    }

    private Value getType() {
        if (last != null) {
            if (last.getText().equals("X")) {
                return Value.ZERO;
            } else {
                return Value.CROSS;
            }
        } else {
            return Value.CROSS;
        }
    }

    private void addValue(Value type, Label label) {
        if (type == Value.CROSS) {
            crosses.add(label);
        } else {
            zeros.add(label);
        }

        last = label;
    }

    public Label[] checkResults() {
        Label[] checkCrosses = checkResult(Value.CROSS);

        if (checkCrosses != null) {
            ended = true;
            return checkCrosses;
        } else {
            Label[] checkZeros = checkResult(Value.ZERO);
            if (checkZeros != null) {
                ended = true;
                return checkZeros;
            }
        }

        return null;
    }

    private Label[] checkResult(Value type) {
        ArrayList<Integer> ids = new ArrayList<>();
        ArrayList<Label> labels = (type == Value.CROSS) ? crosses : zeros;

        for (Label label: labels) {
            String idText = ((Node) label).getId().toString();
            ids.add(Integer.parseInt(idText.substring(1)));
        }

        int[][] possibleFinals = {
                {1,4,7}, {2,5,8}, {3,6,9},
                {1,2,3}, {4,5,6}, {7,8,9},
                {1,5,9}, {3,5,7}
        };

        for (int[] idsList: possibleFinals) {
            Label[] result = new Label[3];

            boolean finded = false;
            for (int i = 0; i < idsList.length; i++) {
                Label label = getById(idsList[i], labels);
                if (label == null) {
                    finded = false;
                    break;
                } else {
                    result[i] = label;
                    finded = true;
                }
            }

            if (finded) {
                return result;
            }
        }

        return null;
    }

    private Label getById(int id, ArrayList<Label> labels) {
        for (Label label: labels) {
            if (label.getId().equals("f" + id)) {
                return label;
            }
        }

        return null;
    }
}
