package puzyrev.sem2.hw7.task2;

import com.sun.org.apache.xml.internal.security.Init;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Paint;

import java.net.URL;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Observable;
import java.util.ResourceBundle;

public class Controller implements Initializable {
    private boolean ended = false;

    private enum Value {
        CROSS,
        ZERO
    }

    private ArrayList<Label> crosses;
    private ArrayList<Label> zeros;
    private Label last = null;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        crosses = new ArrayList<>();
        zeros = new ArrayList<>();
    }

    public void putValue(MouseEvent event) {
        if (!ended) {
            String id = ((Node)event.getSource()).getId();
            Label field = (Label) event.getSource();

            if (field.getText().equals("")) {
                Value type = getType();
                addValue(type, id, field);
                String text = (type == Value.CROSS) ? "X" : "O";
                field.setText(text);

                checkResult(Value.CROSS);
                checkResult(Value.ZERO);
            }
        }
    }

    private Value getType() {
        if (last != null) {
            if (last.getText() == "X") {
                return Value.ZERO;
            } else {
                return Value.CROSS;
            }
        } else {
            return Value.CROSS;
        }
    }

    private void addValue(Value type, String id, Label label) {
        if (type == Value.CROSS) {
            crosses.add(label);
        } else {
            zeros.add(label);
        }

        last = label;
    }

    private void checkResult(Value type) {
        ArrayList<Integer> ids = new ArrayList<>();
        ArrayList<Label> labels = (type == Value.CROSS) ? crosses : zeros;

        for (Label label: labels) {
            String idText = ((Node) label).getId().toString();
            ids.add(Integer.parseInt(idText.substring(1)));
        }

        if (ids.size() == 3) {
            int remainder = 3;

            boolean result = false;
            for (Integer id: ids) {
                if (remainder != 3) {
                    if (remainder == (id % 3)) {
                        result = true;
                    } else {
                        result = false;
                        break;
                    }
                } else {
                    remainder = (id % 3);
                }
            }

            if (!result) {
                ArrayList<Integer> remainders = new ArrayList<>();
                remainders.add(0);
                remainders.add(1);
                remainders.add(2);

                for (Integer id: ids) {
                    if (remainders.contains(id % 3)) {
                        remainders.remove((Integer) (id % 3));
                    } else {
                        return;
                    }
                }

                colorize(type);
                ended = true;
            } else {
                colorize(type);
                ended = true;
            }
        }
    }

    private void colorize(Value type) {
        ArrayList<Label> labelsList = (type == Value.CROSS) ? crosses : zeros;

        for (Label label: labelsList) {
            label.setTextFill(Paint.valueOf("red"));
        }
    }
}
